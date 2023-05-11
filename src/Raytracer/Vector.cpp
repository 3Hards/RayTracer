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

void Raytracer::Vector::hitPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> hittedPrimitive)
{
    Transformable::Point3d hitPos = getPos();
    Transformable::Point3d lightPos = _light->getPos();
    Transformable::Point3d axis{hitPos.x - lightPos.x, hitPos.y - lightPos.y, hitPos.z - lightPos.z};
    std::shared_ptr<Raytracer::IVector> vector = shared_from_this();

    setAxis(axis.normalize());
    _hittedPrimitive = hittedPrimitive;
    for (auto primitive : _primitives) {
        if (_hittedPrimitive != primitive && primitive->checkHit(vector)) {
            _res = Display::Color{0, 0, 0};
            return;
        }
    }
    compute();
}

void Raytracer::Vector::compute()
{
    Transformable::Point3d materialBaseColor = _hittedPrimitive->getMaterialBaseColor();
    _normal = _hittedPrimitive->getNormalVector();
    _scalarNL = _normal.dot(_light->getLightDirection(shared_from_this()));
    if (_scalarNL < 0) {
        _lightColors.push_back({0, 0, 0});
        return;
    }
    Transformable::Point3d lightColor = getLightColor();
    Transformable::Point3d diffuse = {
        lightColor.x * materialBaseColor.x * _scalarNL,
        lightColor.y * materialBaseColor.y * _scalarNL,
        lightColor.z * materialBaseColor.z * _scalarNL
    };
    _lightColors.push_back(diffuse);
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
    std::vector<Transformable::Point3d> hittedPoints;

    for (auto primitive : _primitives) {
        if (primitive->checkHit(vector)) {
            hittedPrimitives.push_back(primitive);
            Transformable::Point3d sub = _pos - _origin;
            hittedPrimitivesDistances.push_back(sub.length());
            hittedPoints.push_back(_pos);
            _pos = _origin;
        }
    }
    if (hittedPrimitives.size() == 0) {
        _res = Display::Color{0, 0, 0};
        return;
    }
    int i = std::distance(std::begin(hittedPrimitivesDistances), std::min_element(std::begin(hittedPrimitivesDistances), std::end(hittedPrimitivesDistances)));
    _pos = hittedPoints[i];
    hitPrimitive(hittedPrimitives[i]);
}

Display::Color Raytracer::Vector::computeColor(std::vector<std::shared_ptr<Transformable::Light::ILight>> lights)
{
    Transformable::Point3d pos2 = _pos;
    Transformable::Point3d axis2 = _axis;
    _res = Display::Color{0, 0, 0};
    _scalarNL = 0;

    for (auto light : lights) {
        _pos = pos2;
        _axis = axis2;
        _origin = pos2;
        _light = light;
        _incident = axis2;
        run();
        _scalarNL = 0;
    }

    if (_lightColors.size() == 0) {
        return _res;
    }

    Transformable::Point3d ambientLightColor = _light->getAmbientLightColor();
    Transformable::Point3d materialBaseColor = _hittedPrimitive->getMaterialBaseColor();
    Transformable::Point3d ambient = {
        ambientLightColor.x * materialBaseColor.x,
        ambientLightColor.y * materialBaseColor.y,
        ambientLightColor.z * materialBaseColor.z
    };

    Transformable::Point3d finalColor = {0, 0, 0};
    
    for (const auto& color : _lightColors) {
        finalColor.x += color.x;
        finalColor.y += color.y;
        finalColor.z += color.z;
    }

    Transformable::Point3d specular = _hittedPrimitive->getSpecular();

    finalColor.x += ambient.x + specular.x;
    finalColor.y += ambient.y + specular.y;
    finalColor.z += ambient.z + specular.z;

    float maxColor = std::max({finalColor.x, finalColor.y, finalColor.z});
    if (maxColor > 1.0) {
        finalColor.x /= maxColor;
        finalColor.y /= maxColor;
        finalColor.z /= maxColor;
    }

    _res = Display::Color{
        static_cast<int>(finalColor.x * 255),
        static_cast<int>(finalColor.y * 255),
        static_cast<int>(finalColor.z * 255)
    };

    _light.reset();
    _hittedPrimitive.reset();
    _scalarNL = 0;
    _lightColors.clear();
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
