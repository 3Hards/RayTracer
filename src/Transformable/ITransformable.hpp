/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ITransformable
*/

#pragma once

#include <cmath>

namespace Transformable {
    class Point3d {
        public:
            double x;
            double y;
            double z;
            Point3d operator*(const Point3d a) {return {x * a.x, y * a.y, z * a.z};};
            Point3d operator*(double a) {return {x * a, y * a, z * a};};
            Point3d operator+(const Point3d a) {return {x + a.x, y + a.y, z + a.z};};
            Point3d operator-(const Point3d a) {return {x - a.x, y - a.y, z - a.z};};
            Point3d cross(const Point3d other) const {
                return {y * other.z - z * other.y,
                    z * other.x - x * other.z,
                    x * other.y - y * other.x};
            };
            double len() const {
                return std::sqrt(x * x + y * y + z * z);
            }
            Point3d normalized() const {
                double length = len();
                return {x / length, y / length, z / length};
            };
    };

    class ITransformable {
        public:
            virtual ~ITransformable() = default;
            virtual Point3d getPos() = 0;
            virtual Point3d getAxis() = 0;
            virtual void setPos(Point3d) = 0;
            virtual void setAxis(Point3d) = 0;
    };
}
