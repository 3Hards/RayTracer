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
            Point3f getPos() final;
            Point3f getAxis() final;
            void setPos(Point3f) final;
            void setAxis(Point3f) final;
            TransformableType getType() final;

        protected:
            Point3f _pos;
            Point3f _axis;
            TransformableType _type;

            ATransformable(Point3f pos, Point3f axis, TransformableType type);
    };
}
