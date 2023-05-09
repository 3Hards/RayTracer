/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#ifdef _WIN32
    #define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <array>
#include "Vector.hpp"
#include "ILight.hpp"

Raytracer::Vector::Vector(
        std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> primitives,
        std::vector<std::shared_ptr<Transformable::Light::ILight>> lights)
    : ATransformable(Transformable::Point3d{0, 0, 0}, Transformable::Point3d{0, 0, 0}), _res({0, 0, 0}), _incident({0, 0, 0}),
    _state(State::INCIDENT), _primitives(primitives), _lights(lights)
{}

Raytracer::Vector::Vector(Transformable::Point3d pos, Transformable::Point3d axis,
        std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> primitives,
        std::vector<std::shared_ptr<Transformable::Light::ILight>> lights)
    : ATransformable(pos, axis), _res({0, 0, 0}), _incident({0, 0, 0}), _state(State::INCIDENT),
    _primitives(primitives), _lights(lights)
{}

double Raytracer::Vector::getScalarRI()
{
    Transformable::Point3d normal = _normal.normalized();
    Transformable::Point3d axis = _axis.normalized();
    Transformable::Point3d R = {2 * _scalarNL * normal.x - axis.x, 2 * _scalarNL * normal.y - axis.y,  2 * _scalarNL * normal.z - axis.z};

    return R.dot(_incident);
}

Transformable::Point3d Raytracer::Vector::getLightColor()
{
    return _lights[0]->getLightColor();
}

void Raytracer::Vector::hitPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive)
{
    if (_state == State::INCIDENT) {
        Transformable::Point3d hitPos = getPos();
        Transformable::Point3d lightPos = _lights[0]->getPos();
        Transformable::Point3d axis{hitPos.x - lightPos.x, hitPos.y - lightPos.y, hitPos.z - lightPos.z};
        setAxis(axis.normalized());
        _hittedPrimitive = primitive;
        _state = State::LIGHT;
    }
}

void Raytracer::Vector::checkHitPrimitives()
{
    std::shared_ptr<Raytracer::IVector> vector = shared_from_this();

    for (auto primitive : _primitives) {
        if (_hittedPrimitive != primitive && primitive->checkHit(vector)) {
            hitPrimitive(primitive);
            return;
        }
    }
    //see later for nearest primitive
    _res = Display::Color{0, 0, 0};
    _state = State::STOP;
}

void Raytracer::Vector::compute()
{
    Transformable::Point3d ambientLightColor = _lights[0]->getAmbientLightColor();
    Transformable::Point3d materialBaseColor = _hittedPrimitive->getMaterialBaseColor();
    Transformable::Point3d ambient = ambientLightColor * materialBaseColor;

    _normal = _hittedPrimitive->getNormalVector();
    _scalarNL = _normal.dot(_axis);
    if (_scalarNL < 0) {
        _res = Display::Color{0, 0, 0};
        _state = State::STOP;
        return;
    }
    Transformable::Point3d lightColor = _lights[0]->getLightColor();
    Transformable::Point3d diffuse = lightColor * materialBaseColor * _scalarNL;
    Transformable::Point3d specular = _hittedPrimitive->getSpecular();
    _res = Display::Color{(int)((ambient.x + diffuse.x + specular.x) * 255), (int)((ambient.y + diffuse.y + specular.y) * 255), (int)((ambient.z + diffuse.z + specular.z) * 255)};
}

int Raytracer::Vector::checkValue(double value)
{
    if (value > 1) {
        return 1;
    }
    if (value < 0) {
        return 0;
    }
    return (int)value;
}

void Raytracer::Vector::checkHitLight()
{
    std::unique_ptr<Raytracer::IVector> vector = std::make_unique<Raytracer::Vector>(*this);
    std::shared_ptr<Raytracer::IVector> SharedVector = shared_from_this();

    if (_lights[0]->checkHit(vector)) {
        /* don't work because we need to keep the nearest primitive
        for (auto primitive : _primitives) {
            if (primitive != _hittedPrimitive && primitive->checkHit(SharedVector)) {
                _res = Display::Color{0, 0, 0};
                _state = State::STOP;
                return;
            }
        }
        */
        compute();
    } else {
        _res = Display::Color{0, 0, 0};
    }
}

void Raytracer::Vector::run()
{
    checkHitPrimitives();
    if (_state == State::STOP) {
        return;
    }
    checkHitLight();
}

Display::Color Raytracer::Vector::computeColor()
{
    _incident = _axis;
    run();

    _distances.clear();
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
