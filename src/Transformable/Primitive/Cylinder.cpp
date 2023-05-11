/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cylinder
*/

#include <cmath>
#include <memory>
#include "Sphere.hpp"
#include "Vector.hpp"
#include "Cylinder.hpp"

Transformable::Primitive::Cylinder::Cylinder(Point3d pos, Point3d axis, double _ray, double height, std::shared_ptr<Material::IMaterial> material) : Transformable::Primitive::APrimitive(material, pos, axis), _ray(_ray), _height(height)
{
}

bool Transformable::Primitive::Cylinder::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    Point3d dist = getAxis() - vectorPos;
    double a = vectorAxis.x * vectorAxis.x + vectorAxis.z * vectorAxis.z;
    double b = 2.0 * (dist.x * vectorAxis.x + dist.z * vectorAxis.z);
    double c = dist.x * dist.x + dist.z * dist.z - _ray * _ray;
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0) {
        return false;
    }

    double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);

    double y1 = vectorPos.y + t1 * vectorAxis.y;
    double y2 = vectorPos.y + t2 * vectorAxis.y;

    double minY = std::min(y1, y2);
    double maxY = std::max(y1, y2);

    if (minY > _height || maxY < 0) {
        return false;
    }

    double t = (minY < 0) ? t2 : t1;

    Point3d hitPos = vectorPos + vectorAxis * t;
    vector->setPos(hitPos);
    _lastHittedVector = vector;
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
