/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#include "Cone.hpp"


Transformable::Primitive::Cone::Cone(Point3d pos, double height, double angle, double radius, std::shared_ptr<Material::IMaterial> material)
    : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _cosAngle(angle), _radius(radius), _height(height)
{
    _axis = {0, 0, 1};
    _axis.normalize();
    _cosAngle = std::cos(angle);
    _radius = radius;
    _height = height;
}



// bool Transformable::Primitive::Cone::checkHit(std::shared_ptr<Raytracer::IVector> vector)
// {
//     Point3d vectorPos = vector->getPos();
//     Point3d vectorAxis = vector->getAxis();

//     Point3d top = _pos + _axis * _height;

//     double a = vectorAxis.x * vectorAxis.x + vectorAxis.y * vectorAxis.y - _cosAngle * _cosAngle * vectorAxis.z * vectorAxis.z;
//     Point3d dist = vectorPos - _pos;
//     double b = 2.0 * (vectorAxis.x * dist.x + vectorAxis.y * dist.y - _cosAngle * _cosAngle * vectorAxis.z * dist.z);
//     double c = dist.x * dist.x + dist.y * dist.y - _cosAngle * _cosAngle * dist.z * dist.z;
//     double discriminant = b * b - 4.00 * a * c;

//     if (discriminant < 0) {
//         return false;
//     }
//     double t = (-b - std::sqrt(discriminant)) / (2.0 * a);
//     if (t < 0) {
//         return false;
//     }
//     Point3d hitPos = vectorPos + vectorAxis * t;
//     double d1 = (hitPos - _pos).dot(_axis);
//     double d2 = (hitPos - top).dot(_axis);

//     if (d1 < 0 || d1 > _height || d2 < 0 || d2 > _height) {
//         return false;
//     }
//     _lastHittedVector = vector;
//     vector->setPos(hitPos);
//     return true;
// }



// bool Transformable::Primitive::Cone::checkHit(std::shared_ptr<Raytracer::IVector> vector)
// {
//     Point3d vectorPos = vector->getPos();
//     Point3d vectorAxis = vector->getAxis();

//     // Compute quadratic coefficients
//     double a = vectorAxis.x * vectorAxis.x + vectorAxis.y * vectorAxis.y - _cosAngle * _cosAngle * vectorAxis.z * vectorAxis.z;
//     Point3d dist = vectorPos - getPos();
//     double b = 2.0 * (vectorAxis.x * dist.x + vectorAxis.y * dist.y - _cosAngle * _cosAngle * vectorAxis.z * dist.z);
//     double c = dist.x * dist.x + dist.y * dist.y - _cosAngle * _cosAngle * dist.z * dist.z;
//     double discriminant = b * b - 4.0 * a * c;

//     if (discriminant < 0) {
//         return false;
//     }

//     // Compute closest hit distance
//     double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
//     double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
//     double t;
//     if (t1 > 0 && t2 > 0) {
//         t = std::min(t1, t2);
//     } else if (t1 > 0) {
//         t = t1;
//     } else if (t2 > 0) {
//         t = t2;
//     } else {
//         return false;
//     }

//     // Update hit vector and return true
//     _lastHittedVector = vector;
//     Point3d hitPos = vectorPos + vectorAxis * t;
//     vector->setPos(hitPos);
//     return true;
// }


bool Transformable::Primitive::Cone::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    double a = vectorAxis.x * vectorAxis.x + vectorAxis.y * vectorAxis.y - _cosAngle * _cosAngle * vectorAxis.z * vectorAxis.z;
    Point3d dist = vectorPos - getPos();
    double b = 2.0 * (vectorAxis.x * dist.x + vectorAxis.y * dist.y - _cosAngle * _cosAngle * vectorAxis.z * dist.z);
    double c = dist.x * dist.x + dist.y * dist.y - _cosAngle * _cosAngle * dist.z * dist.z;
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



Transformable::Point3d Transformable::Primitive::Cone::getNormalVector()
{
    Transformable::Point3d lastHit = _lastHittedVector->getPos();
    Transformable::Point3d pos = getPos();
    Transformable::Point3d normal = {lastHit.x - pos.x, lastHit.y - pos.y, lastHit.z - pos.z};
    normal.normalize();
    return normal;
}
