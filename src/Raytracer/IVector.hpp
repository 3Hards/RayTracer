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
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class IPrimitive;
    }
    namespace Light {
        class ILight {};
    }
}

namespace Raytracer {
    class IVector {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;
            virtual std::tuple<bool, Display::Color, Transformable::Point3f> run(Transformable::Light::ILight) = 0;
    };
}

namespace Transformable {
    namespace Primitive {
        class IPrimitive {
            public:
                std::tuple<bool, Display::Color> checkHit(Raytracer::IVector &) {
                    return std::make_tuple(true, Display::Color{1, 1, 1});
                }
        };
    }
}
