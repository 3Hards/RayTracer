/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "ALight.hpp"

namespace Transformable {
    namespace Light {
        class Ambient : public ALight {
            public:
                Ambient(Display::Color, float brightness, Point3d pos);
        };
    }
}
