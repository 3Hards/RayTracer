/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#ifdef _WIN32
    #define _USE_MATH_DEFINES
#endif
#include <iostream>
#include <cmath>
#include <array>
#include "Vector.hpp"
#include "ILight.hpp"

Raytracer::Vector::Vector(Transformable::Point3d pos, Transformable::Point3d axis)
    : ATransformable(pos, axis), _res({0, 0, 0}), _incident({0, 0, 0}), _state(State::INCIDENT)
{}

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> primitives)
{
    _primitives = primitives;
}

double Raytracer::Vector::getScalarRI()
{
    Transformable::Point3d normal = normalize(_normal);
    Transformable::Point3d axis = normalize(_axis);
    Transformable::Point3d R = {2 * _scalarNL * normal.x - axis.x, 2 * _scalarNL * normal.y - axis.y,  2 * _scalarNL * normal.z - axis.z};

    return computeScalarProduct(R, _incident);
}

Transformable::Point3d Raytracer::Vector::getLightColor()
{
    return _light->getLightColor();
}

Transformable::Point3d Raytracer::Vector::normalize(Transformable::Point3d toNormalize)
{
    double length = std::sqrt(toNormalize.x * toNormalize.x + toNormalize.y * toNormalize.y + toNormalize.z * toNormalize.z);
    return {toNormalize.x / length, toNormalize.y / length, toNormalize.z / length};
}

Transformable::Point3d Raytracer::Vector::normalize()
{
    return normalize(_axis);
}

void Raytracer::Vector::moveForward()
{
    double distance = std::sqrt(_axis.x * _axis.x + _axis.y * _axis.y + _axis.z * _axis.z);
    double x = _axis.x /= distance;
    double y = _axis.y /= distance;
    double z = _axis.z /= distance;
    _pos.x += x;
    _pos.y += y;
    _pos.z += z;
}

void Raytracer::Vector::hitPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive)
{
    if (_state == State::INCIDENT) {
        Transformable::Point3d hitPos = getPos();
        Transformable::Point3d lightPos = _light->getPos();
        Transformable::Point3d axis{lightPos.x - hitPos.x, lightPos.y - hitPos.y, lightPos.z - hitPos.z};
        setAxis(axis);
        _hittedPrimitive = primitive;
        _state = State::LIGHT;
    } else if (_state == State::LIGHT) {
        _res = Display::Color{0, 0, 0};
        _state = State::STOP;
    }
}

void Raytracer::Vector::checkHitPrimitives()
{
    std::shared_ptr<Raytracer::IVector> vector = shared_from_this();

    for (auto primitive : _primitives) {
        if (primitive->checkHit(vector)) {
            hitPrimitive(primitive);
        }
    }
}

double Raytracer::Vector::computeScalarProduct(Transformable::Point3d fst, Transformable::Point3d scd)
{
    fst = normalize(fst);
    scd = normalize(scd);
    return fst.x * scd.x + fst.y * scd.y + fst.z * scd.z;
}

void Raytracer::Vector::compute()
{
    Transformable::Point3d ambientLightColor = _light->getAmbientLightColor();
    Transformable::Point3d materialBaseColor = _hittedPrimitive->getMaterialBaseColor();
    Transformable::Point3d ambient = {
        ambientLightColor.x * materialBaseColor.x,
        ambientLightColor.y * materialBaseColor.y,
        ambientLightColor.z * materialBaseColor.z
    };
    _normal = _hittedPrimitive->getNormalVector()->getAxis();
    _scalarNL = computeScalarProduct(_normal, _axis);
    if (_scalarNL < 0) {
        _res = Display::Color{0, 0, 0};
        return;
    }
    Transformable::Point3d lightColor = _light->getLightColor();
    std::cout << "lightColor " << lightColor.x << " " << lightColor.y << " " << lightColor.z << std::endl << "materialBaseColor " << materialBaseColor.x << " " << materialBaseColor.y << " " << materialBaseColor.z << std::endl;
    Transformable::Point3d diffuse = {lightColor.x * materialBaseColor.x * _scalarNL, lightColor.y * materialBaseColor.y * _scalarNL, lightColor.z * materialBaseColor.z * _scalarNL};
    Transformable::Point3d specular = _hittedPrimitive->getSpecular();
    std::cout << "diffuse " << diffuse.x << " " << diffuse.y << " " << diffuse.z << std::endl << "ambient " << ambient.x << " " << ambient.y << " " << ambient.z << std::endl;
    _res = Display::Color{(int)((ambient.x + diffuse.x + specular.x) * 255), (int)((ambient.y + diffuse.y + specular.y) * 255), (int)((ambient.z + diffuse.z + specular.z) * 255)};
}

void Raytracer::Vector::checkHitLight()
{
    std::unique_ptr<Raytracer::IVector> vector = std::make_unique<Raytracer::Vector>(*this);

    if (_light->checkHit(vector)) {
        if (_state == State::INCIDENT) {
            _res = Display::Color{0, 0, 0};
        } else if (_state == State::LIGHT) {
            compute();
        }
        _state = State::STOP;
    }
}

void Raytracer::Vector::checkDistances()
{
    std::vector<double> prevDistances = _distances;

    updateDistances();
    for (std::size_t i = 0; i < prevDistances.size(); i++) {
        if (prevDistances[i] >= _distances[i]) {
            return;
        }
    }
    _res = Display::Color{0, 0, 0};
    _state = State::STOP;
}

void Raytracer::Vector::updateDistances()
{
    std::vector <double> distances;

    for (auto primitive : _primitives) {
        Transformable::Point3d pos = primitive->getPos();
        distances.push_back(pow(pow(pos.x - _pos.x, 2) + pow(pos.y - _pos.y, 2) + pow(pos.z - _pos.z, 2), 0.5));
    }
    _distances = distances;
}

void Raytracer::Vector::run()
{
    updateDistances();

    while (_state != State::STOP) {
        moveForward();
        if (_state == State::INCIDENT) {
            checkDistances();
        }
        checkHitPrimitives();
        checkHitLight();
    }
}

Display::Color Raytracer::Vector::computeColor(std::shared_ptr<Transformable::Light::ILight> light)
{
    _light = light;
    _incident = _axis;
    run();

    _distances.clear();
    _light.reset();
    _hittedPrimitive.reset();
    _state = State::INCIDENT;
    _scalarNL = 0;
    return _res;
}

Transformable::Point3d Raytracer::Vector::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3d Raytracer::Vector::getAxis()
{
    return ATransformable::getAxis();
}

void Raytracer::Vector::setPos(Transformable::Point3d pos)
{
    ATransformable::setPos(pos);
}

void Raytracer::Vector::setAxis(Transformable::Point3d axis)
{
    ATransformable::setAxis(axis);
}
