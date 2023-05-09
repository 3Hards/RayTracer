/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Directional header
*/

#include "ALight.hpp"

namespace Transformable {
    namespace Light {
        class Directional : public ALight {
            public:
                Directional(Display::Color, float brightness, Point3d pos, Point3d direction);
                Transformable::Point3d getLightColor(std::shared_ptr<Raytracer::IVector>) final;
            private:
                Point3d _direction;
        };
    }
}