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

    double a = dot(vectorAxis, vectorAxis);
    Point3d dist = vectorPos - _pos;
    double b = 2.0 * dot(vectorAxis, dist);
    double c = dot(dist, dist) - _ray * _ray;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    double t = std::min(t1, t2);
    if (t < 0) {
        return false;
    }
    _lastHittedVector = vector;
    Point3d hitPos = vectorPos + vectorAxis * t;
    vector->setPos(hitPos);
    return true;
}

std::shared_ptr<Raytracer::IVector> Transformable::Primitive::Sphere::getNormalVector()
{
    Transformable::Point3d lastHit = _lastHittedVector->getPos();
    return std::make_shared<Raytracer::Vector>(_pos, Point3d{lastHit.x - _pos.x, lastHit.y - _pos.y, lastHit.z - _pos.z});
}
