/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#include "Cone.hpp"

Transformable::Primitive::Cone::Cone(Point3d pos, double ray, std::shared_ptr<Material::IMaterial> material) : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _ray(ray), _height(1.0), _cosAngle(std::cos(30.0 * M_PI / 180.0))
{
}

bool Transformable::Primitive::Cone::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    // Compute quadratic coefficients
    double a = vectorAxis.dot(vectorAxis) - _cosAngle * _cosAngle * vectorPos.y * vectorPos.y;
    double b = 2.0 * (vectorPos.y * vectorAxis.y * (1.0 - _cosAngle * _cosAngle) - vectorAxis.dot(getPos() - vectorPos) * _cosAngle * _cosAngle);
    double c = (getPos() - vectorPos).dot(getPos() - vectorPos) - _cosAngle * _cosAngle * vectorPos.y * vectorPos.y;

    // Compute discriminant
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0) {
        return false;
    }

    // Compute closest hit distance
    double t = (-b - std::sqrt(discriminant)) / (2.0 * a);
    if (t < 0) {
        return false;
    }

    // Update hit vector and return true
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
