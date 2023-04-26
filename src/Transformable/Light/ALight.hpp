/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "ILight.hpp"
#include "ATransformable.hpp"

namespace Transformable {
    namespace Light {
        class ALight : public ILight, public ATransformable {
            public:
                ALight(Display::Color, float brightness, Point3f pos);
                float getBrightness();
                Point3f getPos() final;
                Point3f getAxis() final;
                void setPos(Point3f pos) final;
                void setAxis(Point3f axis) final;
                TransformableType getType() final;
            protected:
                Display::Color _color;
                float _brightness;
        };
    }
}
