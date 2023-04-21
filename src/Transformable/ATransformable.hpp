/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable header
*/

#pragma once

#include "ITransformable.hpp"

namespace Transformable {
    class ATransformable : public ITransformable {
        public:
            virtual ATransformable() = default;
            Point3f getPos();
            Point3f getAxis();
            void setPos(Point3f);
            void setAxis(Point3f);
            TransformableType getType();

            Point3f _pos;
            Point3f _axis;
            TransformableType _type;
    };
}
