/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ITransformable
*/

#pragma once

#include "Point3d.hpp"

namespace Transformable {
    class ITransformable {
        public:
            virtual ~ITransformable() = default;
            virtual Point3d getPos() = 0;
            virtual Point3d getAxis() = 0;
            virtual void setPos(Point3d) = 0;
            virtual void setAxis(Point3d) = 0;
    };
}
