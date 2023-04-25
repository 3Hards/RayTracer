/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "ALight.hpp"

namespace Transformable {
    namespace Light {
        class Ambiant : public ALight {
            public:
                Ambiant(Display::Color, float brightness, Point3f pos);
                std::tuple<bool, Display::Color> checkHit(std::unique_ptr<Raytracer::IVector>&) final;
        };
    }
}
