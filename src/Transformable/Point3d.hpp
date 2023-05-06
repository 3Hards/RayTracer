/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Point3d header
*/

#pragma once

namespace Transformable {
    struct Point3d {
        public:
            double x;
            double y;
            double z;
            Point3d operator*(const Point3d a) const;
            Point3d operator*(double a) const;
            Point3d operator/(double a) const;
            Point3d operator+(const Point3d a) const;
            Point3d operator-(const Point3d a) const;
            Point3d cross(const Point3d other) const;
            double len() const;
            Point3d normalized() const;
            double scalarProduct(const Point3d other) const;
    };
}
