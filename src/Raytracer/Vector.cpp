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

Raytracer::Vector::Vector(Transformable::Point3f pos, Transformable::Point3f axis)
    : ATransformable(pos, axis, Transformable::TransformableType::VECTOR),
    _hittedObject(HittedObject::UNDEFINED), _hittedColor(Display::Color{0, 0, 0}), _toLight(false)
{}

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> primitives)
{
    _primitives = primitives;
}

void Raytracer::Vector::toLight()
{
    _toLight = true;
}

Raytracer::HittedObject Raytracer::Vector::getHittedObject()
{
    return _hittedObject;
}

Display::Color Raytracer::Vector::getHittedColor()
{
    return _hittedColor;
}

std::shared_ptr<Raytracer::IVector> Raytracer::Vector::getHittedNormalVector()
{
    return _hittedNormalVector;
}

double Raytracer::Vector::toRad(double degree)
{
    return degree * (M_PI / 180);
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

bool Raytracer::Vector::checkHitPrimitives()
{
    std::unique_ptr<Raytracer::IVector> vector = std::make_unique<Raytracer::Vector>(*this);

    for (auto primitive : _primitives) {
        if (primitive->checkHit(vector)) {
            _hittedObject = HittedObject::PRIMITIVE;
            _hittedColor = primitive->getColor();
            _hittedNormalVector = primitive->getNormalVector();
            return true;
        }
    }
    return false;
}

bool Raytracer::Vector::checkHitLight(std::shared_ptr<Transformable::Light::ILight> light)
{
    std::unique_ptr<Raytracer::IVector> vector = std::make_unique<Raytracer::Vector>(*this);

    if (light->checkHit(vector)) {
        _hittedObject = HittedObject::LIGHT;
        return true;
    }
    return false;
}

bool Raytracer::Vector::checkDistances(std::vector<double> &prevDistances)
{
    std::vector<double> newDistances = getDistances();

    for (std::size_t i = 0; i < prevDistances.size(); i++) {
        if (prevDistances[i] >= newDistances[i]) {
            prevDistances = newDistances;
            return false;
        }
    }
    return true;
}

std::vector<double> Raytracer::Vector::getDistances()
{
    std::vector <double> _distances;

    for (auto primitive : _primitives) {
        Transformable::Point3f pos = primitive->getPos();
        _distances.push_back(pow(pow(pos.x - _pos.x, 2) + pow(pos.y - _pos.y, 2) + pow(pos.z - _pos.z, 2), 0.5));

    }
    return _distances;
}

void Raytracer::Vector::run(std::shared_ptr<Transformable::Light::ILight> light)
{
    std::vector<double> prevDistances = getDistances();
    bool moveInVoid = false;

    while (moveInVoid == false || _toLight) {
        moveForward();
        moveInVoid = checkDistances(prevDistances);
        if (checkHitPrimitives() || checkHitLight(light)) {
            return;
        }
    }
    _hittedObject = HittedObject::VOID;
    return;
}

Transformable::Point3f Raytracer::Vector::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3f Raytracer::Vector::getAxis()
{
    return ATransformable::getAxis();
}

void Raytracer::Vector::setPos(Transformable::Point3f pos)
{
    ATransformable::setPos(pos);
}

void Raytracer::Vector::setAxis(Transformable::Point3f axis)
{
    ATransformable::setAxis(axis);
}

Transformable::TransformableType Raytracer::Vector::getType()
{
    return ATransformable::getType();
}
