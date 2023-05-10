/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#pragma once

#include "ILight.hpp"
#include "ATransformable.hpp"

namespace Transformable {
    namespace Light {
        class ALight : public ILight, public ATransformable {
            public:
                ALight(Display::Color, float brightness, Point3d pos);
                Transformable::Point3d getAmbientLightColor() final;
                Transformable::Point3d getLightColor() final;
                Point3d getPos() final;
                Point3d getAxis() final;
                void setPos(Point3d pos) final;
                void setAxis(Point3d axis) final;
            protected:
                Transformable::Point3d _color;
                Transformable::Point3d _ambientColor;
                float _brightness;
        };
    }
}
