/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Point3d
*/

#include "Point3d.hpp"
#include <cmath>

Transformable::Point3d Transformable::Point3d::operator*(const Transformable::Point3d a) const
{
    return {x * a.x, y * a.y, z * a.z};
}

Transformable::Point3d Transformable::Point3d::operator*(double a) const
{
    return {x * a, y * a, z * a};

}
Transformable::Point3d Transformable::Point3d::operator/(double a) const
{
    return {x / a, y / a, z / a};
}

Transformable::Point3d Transformable::Point3d::operator+(const Point3d a) const
{
    return {x + a.x, y + a.y, z + a.z};
}

Transformable::Point3d Transformable::Point3d::operator-(const Point3d a) const
{
    return {x - a.x, y - a.y, z - a.z};
}

Transformable::Point3d Transformable::Point3d::cross(const Point3d other) const
{
    return {y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x};
}

double Transformable::Point3d::len() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Transformable::Point3d Transformable::Point3d::normalized() const {
    double length = len();
    return {x / length, y / length, z / length};
}

Transformable::Point3d Transformable::Point3d::operator+(double a) const
{
    return {x + a, y + a, z + a};
}

double Transformable::Point3d::dot(const Point3d other) const {
    Point3d fst = this->normalized();
    Point3d scd = other.normalized();
    return fst.x * scd.x + fst.y * scd.y + fst.z * scd.z;
}
