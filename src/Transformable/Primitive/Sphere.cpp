/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#include <cmath>
#include <memory>
#include "Sphere.hpp"
#include "Vector.hpp"

Transformable::Primitive::Sphere::Sphere(Point3d pos, double _ray, std::shared_ptr<Material::IMaterial> material) : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _ray(_ray)
{
}

bool Transformable::Primitive::Sphere::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    double distance = sqrt(pow(vectorPos.x - _pos.x, 2) + pow(vectorPos.y - _pos.y, 2) + pow(vectorPos.z - _pos.z, 2));

    if (distance <= _ray) {
        _lastHittedVector = vector;
        return true;
    }
    return false;
}

std::shared_ptr<Raytracer::IVector> Transformable::Primitive::Sphere::getNormalVector()
{
    Transformable::Point3d lastHit = _lastHittedVector->getPos();
    return std::make_shared<Raytracer::Vector>(_pos, Point3d{lastHit.x - _pos.x, lastHit.y - _pos.y, lastHit.z - _pos.z});
}
