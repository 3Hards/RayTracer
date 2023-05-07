/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** Plane
*/

#include <cmath>
#include "Plane.hpp"
#include "Vector.hpp"

namespace Transformable {
    namespace Primitive {

Plane::Plane(Point3d pos, double length, double width, std::shared_ptr<Material::IMaterial> material)
    : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _length(length), _width(width)
{
    _depth = 1;
}

bool Plane::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();

    double distanceX = fabs(vectorPos.x - _pos.x);
    double distanceY = fabs(vectorPos.y - _pos.y);
    double distanceZ = fabs(vectorPos.z - _pos.z);

    if (distanceX <= (_length / 2) &&
        distanceY <= (_width / 2) &&
        distanceZ <= (_depth / 2)) {
        _lastHittedVector = vector;
        return true;
    } else {
        return false;
    }
}

Transformable::Point3d Plane::getNormalVector()
{
    return Point3d{0, 0, 1};
}

    }
}
