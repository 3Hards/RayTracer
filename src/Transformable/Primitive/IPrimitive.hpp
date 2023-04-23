/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#pragma once

#include "ITransformable.hpp"
#include "DisplayStructs.hpp"
#include <tuple>

namespace Raytracer {
    class IVector;
}

namespace Transformable {
    namespace Primitive {
        class IPrimitive : public ITransformable {
            public:
                std::tuple<bool, Display::Color> checkHit(Raytracer::IVector);
        };
    }
}
