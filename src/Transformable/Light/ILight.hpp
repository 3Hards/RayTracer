/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILight
*/

#pragma once

#include <memory>
#include "DisplayStructs.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Light {
        class ILight {
            public:
                virtual ~ILight() = default;
                virtual bool checkHit(std::unique_ptr<Raytracer::IVector>&) = 0;
                virtual Display::Color getColor() = 0;
                virtual float getBrightness() = 0;
        };
    }
}
