/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILight
*/

#pragma once

#include <tuple>
#include <memory>
#include "DisplayStructs.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Light {
        class ILight {
            public:
                virtual ~ILight() = default;
                virtual std::tuple<bool, Display::Color> checkHit(std::unique_ptr<Raytracer::IVector>&) = 0;
        };
    }
}
