/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ITransformable
*/

#pragma once

namespace Transformable {
    struct Point3d {
        public:
            double x;
            double y;
            double z;
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
