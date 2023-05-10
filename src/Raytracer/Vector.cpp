/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#ifdef _WIN32
    #define _USE_MATH_DEFINES
#endif
#include <algorithm>
#include <cmath>
#include <array>
#include "Vector.hpp"
#include "ILight.hpp"

Raytracer::Vector::Vector(Transformable::Point3d pos, Transformable::Point3d axis)
    : ATransformable(pos, axis), _res({0, 0, 0}), _incident({0, 0, 0})
{}

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> primitives)
{
    _primitives = primitives;
}

double Raytracer::Vector::getScalarRI()
{
    return (2 * _scalarNL * _normal.normalize() - _light->getLightDirection(shared_from_this()).normalize()).dot(_incident);
}

Transformable::Point3d Raytracer::Vector::getLightColor()
{
    return _light->getLightColor();
}

void Raytracer::Vector::hitPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive)
{
    Transformable::Point3d hitPos = getPos();
    Transformable::Point3d lightPos = _light->getPos();
    Transformable::Point3d axis{hitPos.x - lightPos.x, hitPos.y - lightPos.y, hitPos.z - lightPos.z};
    setAxis(axis.normalize());
    _hittedPrimitive = primitive;
    compute();
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
    _normal = _hittedPrimitive->getNormalVector();
    _scalarNL = _normal.dot(_light->getLightDirection(shared_from_this()));
    if (_scalarNL < 0) {
        _res = Display::Color{0, 0, 0};
        return;
    }
    Transformable::Point3d lightColor = getLightColor();
    Transformable::Point3d diffuse = {lightColor.x * materialBaseColor.x * _scalarNL, lightColor.y * materialBaseColor.y * _scalarNL, lightColor.z * materialBaseColor.z * _scalarNL};
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

void Raytracer::Vector::run()
{
    std::shared_ptr<Raytracer::IVector> vector = shared_from_this();
    std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> hittedPrimitives;
    std::vector<double> hittedPrimitivesDistances;

    for (auto primitive : _primitives) {
        if (primitive->checkHit(vector)) {
            hittedPrimitives.push_back(primitive);
            Transformable::Point3d sub = _pos - _origin;
            hittedPrimitivesDistances.push_back(sub.length());
        }
    }
    if (hittedPrimitives.size() == 0) {
        _res = Display::Color{0, 0, 0};
        return;
    }
    int i = std::distance(std::begin(_primitives), std::min_element(std::begin(_primitives), std::end(_primitives)));
    hitPrimitive(_primitives[i]);
}

Display::Color Raytracer::Vector::computeColor(std::shared_ptr<Transformable::Light::ILight> light)
{
    _origin = _pos;
    _light = light;
    _incident = _axis;
    run();

    _distances.clear();
    _light.reset();
    _hittedPrimitive.reset();
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
