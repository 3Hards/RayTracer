/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cylinder
*/

#include "Cylinder.hpp"


Transformable::Primitive::Cylinder::Cylinder(Point3d pos, Point3d axis, double ray, double height, std::shared_ptr<Material::IMaterial> material) : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _ray(ray), _height(height), _axis(axis)
{
    _axis.normalize();
}

bool Transformable::Primitive::Cylinder::checkHit(std::shared_ptr<Raytracer::IVector> vector)
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

Transformable::Point3d Transformable::Primitive::Cylinder::getNormalVector()
{
    Transformable::Point3d lastHit = _lastHittedVector->getPos();
    Transformable::Point3d pos = getPos();
    Transformable::Point3d normal = {lastHit.x - pos.x, lastHit.y - pos.y, lastHit.z - pos.z};
    normal.normalize();
    return normal;
}
