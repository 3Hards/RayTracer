/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** Sphere
*/

#include <cmath>
#include <memory>
#include "Sphere.hpp"
#include "Vector.hpp"

Transformable::Primitive::Sphere::Sphere(Point3f pos, double _ray, std::shared_ptr<Material::IMaterial> material) : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _ray(_ray), _lastHit({0, 0, 0})
{
}

bool Transformable::Primitive::Sphere::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3f vectorPos = vector->getPos();
    double distance = sqrt(pow(vectorPos.x - _pos.x, 2) + pow(vectorPos.y - _pos.y, 2) + pow(vectorPos.z - _pos.z, 2));

    if (distance <= _ray) {
        _lastHit = vectorPos;
        _color = _material->getColor(vector);
        return true;
    }
    return false;
}

std::shared_ptr<Raytracer::IVector> Transformable::Primitive::Sphere::getNormalVector()
{
    return std::make_shared<Raytracer::Vector>(_pos, Point3f{_lastHit.x - _pos.x, _lastHit.y - _pos.y, _lastHit.z - _pos.z});
}
