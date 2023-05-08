/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ITransformable
*/

#pragma once

#include <cmath>

namespace Transformable {
    struct Point3d {
        public:
            double x;
            double y;
            double z;

        Point3d normalize() const {
            double length = sqrt(x * x + y * y + z * z);
            return {x / length, y / length, z / length};
        }
        double dot(Point3d v) const {
            return x * v.x + y * v.y + z * v.z;
        }
        Point3d cross(Point3d v) const {
            return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
        }
        double length() const {
            return sqrt(x * x + y * y + z * z);
        }
    };

    Point3d operator-(Point3d a, Point3d b);
    Point3d operator+(Point3d a, Point3d b);
    Point3d operator*(Point3d a, double b);
    Point3d operator/(Point3d a, double b);
    Point3d operator*(double a, Point3d b);

    class ITransformable {
        public:
            virtual ~ITransformable() = default;
            virtual Point3d getPos() = 0;
            virtual Point3d getAxis() = 0;
            virtual void setPos(Point3d) = 0;
            virtual void setAxis(Point3d) = 0;
    };
}
