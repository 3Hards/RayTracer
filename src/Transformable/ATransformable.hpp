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
            Point3d getPos() override;
            Point3d getAxis() override;
            void setPos(Point3d) override;
            void setAxis(Point3d) override;

        protected:
            Point3d _pos;
            Point3d _axis;

            ATransformable(Point3d pos, Point3d axis);
    };
}
