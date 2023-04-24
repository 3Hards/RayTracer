/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#pragma once

#include <tuple>
#include <memory>
#include "ITransformable.hpp"
#include "DisplayStructs.hpp"

namespace Raytracer {
    class IVector;
}

namespace Transformable {
    namespace Primitive {
        class IPrimitive : public ITransformable {
            public:
                virtual std::tuple<bool, Display::Color> checkHit(std::unique_ptr<Raytracer::IVector>) = 0;
        };
    }
}
