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
    Point3d operator*(double a, Point3d b) {
        return {a * b.x, a * b.y, a * b.z};
    }
    Point3d Point3d::normalize() const {
        double length = sqrt(x * x + y * y + z * z);
        return {x / length, y / length, z / length};
    }
    double Point3d::dot(Point3d v) const {
        return x * v.x + y * v.y + z * v.z;
    }
    Point3d Point3d::cross(Point3d v) const {
        return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
    }
    double Point3d::length() const {
        return sqrt(x * x + y * y + z * z);
    }
}
