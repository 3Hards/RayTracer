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

double dot(const Transformable::Point3d& a, const Transformable::Point3d& b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

bool Transformable::Primitive::Sphere::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    double a = vectorAxis.dot(vectorAxis);
    Point3d dist = vectorPos - getPos();
    double b = 2.0 * dist.dot(vectorAxis);
    double c = dist.dot(dist) - _ray * _ray;
    double discriminant = b * b - 4.00 * a * c;

    if (discriminant < 0) {
        return false;
    }
    double t = (-b - std::sqrt(discriminant)) / (2.0 * a);
    if (t < 0) {
        return false;
    }
    _lastHittedVector = vector;
    Point3d hitPos = vectorPos + vectorAxis * t;
    vector->setPos(hitPos);
    return true;
}

Transformable::Point3d Transformable::Primitive::Sphere::getNormalVector()
{
    Transformable::Point3d lastHit = _lastHittedVector->getPos();
    Transformable::Point3d pos = getPos();
    Transformable::Point3d normal = {lastHit.x - pos.x, lastHit.y - pos.y, lastHit.z - pos.z};
    normal.normalize();
    return normal;
}
