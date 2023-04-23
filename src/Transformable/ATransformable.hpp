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
            Point3f getPos() override;
            Point3f getAxis() override;
            void setPos(Point3f) override;
            void setAxis(Point3f) override;
            TransformableType getType() override;

        protected:
            Point3f _pos;
            Point3f _axis;
            TransformableType _type;

            ATransformable(Point3f pos, Point3f axis, TransformableType type);
    };
}
