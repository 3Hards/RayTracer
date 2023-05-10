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

        Point3d normalize();
        double dot(Point3d v) const;
        Point3d cross(Point3d v) const;
        double length() const;
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
