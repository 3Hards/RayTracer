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
#include "ILight.hpp"
#include "IPrimitive.hpp"

namespace Raytracer {
    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;
            virtual std::tuple<bool, Display::Color, Transformable::Point3f> run(std::shared_ptr<Transformable::Light::ILight> light) = 0;
    };
}
