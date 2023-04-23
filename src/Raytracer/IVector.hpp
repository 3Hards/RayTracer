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
#include "IPrimitive.hpp"

namespace Transformable {
    namespace Light {
        class ILight {};
    }
}

namespace Raytracer {
    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;
            virtual std::tuple<bool, Display::Color, Transformable::Point3f> run(Transformable::Light::ILight) = 0;
    };
}
