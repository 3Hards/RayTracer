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

Raytracer::Vector::Vector(Transformable::Point3d pos, Transformable::Point3d axis)
    : ATransformable(pos, axis), _res({0, 0, 0}), _incident({0, 0, 0})
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
    std::shared_ptr<Raytracer::IVector> vector = shared_from_this();

    return _light->getLightColor(vector);
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

void Raytracer::Vector::hitPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive)
{
    Transformable::Point3d hitPos = getPos();
    Transformable::Point3d lightPos = _light->getPos();
    Transformable::Point3d axis{hitPos.x - lightPos.x, hitPos.y - lightPos.y, hitPos.z - lightPos.z};
    setAxis(axis.normalize());
    _hittedPrimitive = primitive;
    compute();
}

double Raytracer::Vector::computeScalarProduct(Transformable::Point3d fst, Transformable::Point3d scd)
{
    fst = normalize(fst);
    scd = normalize(scd);
    double res = fst.x * scd.x + fst.y * scd.y + fst.z * scd.z;
    return res > 1 ? 1 : res;
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
    _scalarNL = computeScalarProduct(_normal, _axis);
    if (_scalarNL < 0) {
        _res = Transformable::Point3d{0, 0, 0};
        return;
    }
    Transformable::Point3d lightColor = getLightColor();
    Transformable::Point3d diffuse = {lightColor.x * materialBaseColor.x * _scalarNL, lightColor.y * materialBaseColor.y * _scalarNL, lightColor.z * materialBaseColor.z * _scalarNL};
    Transformable::Point3d specular = _hittedPrimitive->getSpecular();
    _res = ambient + diffuse + specular;
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

    for (auto primitive : _primitives) {
        if (_hittedPrimitive != primitive && primitive->checkHit(vector)) {
            hitPrimitive(primitive);
            return;
        }
    }
    _res = Transformable::Point3d{0, 0, 0};
}

Display::Color Raytracer::Vector::computeColor(std::vector<std::shared_ptr<Transformable::Light::ILight>> lights)
{
    Transformable::Point3d res{0, 0, 0};

    _incident = _axis;
    for (auto light : lights) {
        _light = light;
        run();
        res = res + _res;
    }
    res = res * 255;
    return Display::Color((int)res.x, (int)res.y, (int)res.z);
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
