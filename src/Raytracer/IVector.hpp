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
    namespace Primitive {
        class IPrimitive;
    }
    namespace Light {
        class ILight {};
    }
}
namespace Material {
    class IMaterial {};
}

namespace Raytracer {
    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;
            virtual std::tuple<bool, Display::Color, Transformable::Point3f> run(std::shared_ptr<Transformable::Light::ILight> light) = 0;
    };
}

namespace Transformable {
    namespace Primitive {
        class IPrimitive : public Transformable::ITransformable {
            public:
                std::tuple<bool, Display::Color> checkHit(Raytracer::IVector &) {
                    return std::make_tuple(true, Display::Color{1, 1, 1});
                }
        };
    }
}
