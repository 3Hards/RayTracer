/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IVector
*/

#pragma once

#include <vector>
#include <memory>
#include "ITransformable.hpp"
#include "DisplayStructs.hpp"

namespace Transformable {
    class IPrimitive;
    class ILight {};
}
namespace Material {
    class IMaterial {};
}

namespace Raytracer {
    class IVector {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>>) = 0;
            virtual std::tuple<bool, Display::Color, Transformable::Point3f> run(Transformable::ILight) = 0;
    };
}

namespace Transformable {
    class IPrimitive {
        public:
            std::tuple<bool, Display::Color> checkHit(Raytracer::IVector &) {
                return std::make_tuple(true, Display::Color{1, 1, 1});
            }
    };
}
