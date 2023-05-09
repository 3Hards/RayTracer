/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "ATransformable.hpp"

Transformable::ATransformable::ATransformable(Point3d pos, Point3d axis) : _pos(pos), _axis(axis)
{
}

Transformable::Point3d Transformable::ATransformable::getPos()
{
    return _pos;
}

Transformable::Point3d Transformable::ATransformable::getAxis()
{
    return _axis;
}

void Transformable::ATransformable::setPos(Point3d pos)
{
    _pos = pos;
}

void Transformable::ATransformable::setAxis(Point3d axis)
{
    _axis = axis;
}

namespace Transformable {
    Point3d operator-(Point3d a, Point3d b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }
    Point3d operator+(Point3d a, Point3d b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }
    Point3d operator*(Point3d a, double b) {
        return {a.x * b, a.y * b, a.z * b};
    }
    Point3d operator/(Point3d a, double b) {
        return {a.x / b, a.y / b, a.z / b};
    }
}
