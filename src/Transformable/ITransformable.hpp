/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ITransformable
*/

#pragma once

#include <cmath>

namespace Transformable {

    /**
     * @brief Point3d class
    */
    struct Point3d {
        public:
            double x;
            double y;
            double z;

        Point3d normalize() const;
        double dot(Point3d v) const;
        Point3d cross(Point3d v) const;
        double length() const;
    };

    Point3d operator-(Point3d a, Point3d b);
    Point3d operator+(Point3d a, Point3d b);
    Point3d operator*(Point3d a, double b);
    Point3d operator/(Point3d a, double b);
    Point3d operator*(double a, Point3d b);

    /**
     * @brief Interface for the transformable
    */
    class ITransformable {
        public:

            /**
             * @brief Transformable destructor
            */
            virtual ~ITransformable() = default;

            /**
             * @brief Get the Pos
             * @return Point3d Pos
            */
            virtual Point3d getPos() = 0;

            /**
             * @brief Get the Axis
             * @return Point3d Axis
            */
            virtual Point3d getAxis() = 0;

            /**
             * @brief Set the Pos
             * @param pos Point3d
             * @return void
            */
            virtual void setPos(Point3d) = 0;

            /**
             * @brief Set the Axis
             * @param axis Point3d
             * @return void
            */
            virtual void setAxis(Point3d) = 0;
    };
}
