/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#include "Cone.hpp"

Transformable::Primitive::Cone::Cone(Point3d pos, double height, double radius, Point3d Axis, std::shared_ptr<Material::IMaterial> material)
    : Transformable::Primitive::APrimitive(material, pos, Axis), _radius(radius), _height(height)
{}

bool Transformable::Primitive::Cone::checkHitBaseCircle(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    Point3d diskNormal = {0, 0, 1};
    Point3d diskCenter = {0, 0, _height};

    double dotProduct = vectorAxis.dot(diskNormal);
    if (dotProduct == 0) {
        return false;
    }
    double t = (diskCenter - vectorPos).dot(diskNormal) / dotProduct;
    if (t < 0) {
        return false;
    }
    Point3d hitPos = vectorPos + vectorAxis * t;
    bool canSeeTheBigCone = vectorAxis.dot(diskNormal) < 0;
    if (canSeeTheBigCone && hitPos.x * hitPos.x + hitPos.y * hitPos.y <= _radius * _radius) {
        _lastHittedVector = vector;
        vector->setPos(hitPos);
        return true;
    }
    return false;
}

bool Transformable::Primitive::Cone::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Transformable::Point3d vectorPos = vector->getPos();
    Transformable::Point3d vectorAxis = vector->getAxis();

    double a = vectorAxis.dot(vectorAxis) - (1 + (_radius * _radius) / (_height * _height)) * (vectorAxis.z * vectorAxis.z);
    Transformable::Point3d dist = vectorPos - getPos();
    double b = 2.0 * (vectorAxis.dot(dist) - (1 + (_radius * _radius) / (_height * _height)) * (vectorAxis.z * dist.z));
    double c = dist.dot(dist) - (1 + (_radius * _radius) / (_height * _height)) * (dist.z * dist.z);
    double discriminant = b * b - 4.00 * a * c;
    
    if (discriminant < 0) {
        return false;
    }
    double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
    // double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
    Point3d hitPos = vectorPos + vector->getAxis() * t1;
    if (hitPos.z >= getPos().z && hitPos.z <= getPos().z + _height) {
        if (checkHitBaseCircle(vector)) {
            return true;
        }
        vector->setPos(hitPos);
        _lastHittedVector = vector;
        return true;
    }
    if (hitPos.z >= getPos().z && hitPos.z <= getPos().z + _height) {
        if (checkHitBaseCircle(vector)) {
            return true;
        }
        vector->setPos(hitPos);
        _lastHittedVector = vector;
        return true;
    }
    if (checkHitBaseCircle(vector)) {
        return true;
    }
    return false;
}

Transformable::Point3d Transformable::Primitive::Cone::getNormalVector()
{
    Point3d I = getPos() + Point3d{0, 0, _height};
    // Point3d P = getPos();
    Point3d A = getPos() + Point3d{_radius, 0, _height};
    Point3d normal = I - A;
    normal.normalize();
    return normal;
}
