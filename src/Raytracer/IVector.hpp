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
#include "IPrimitive.hpp"

namespace Transformable {
    namespace Light {
        class ILight;
    }
}

namespace Raytracer {
    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;
            virtual Display::Color computeColor(std::shared_ptr<Transformable::Light::ILight> light) = 0;
            virtual double getScalarRI() = 0;
            virtual Transformable::Point3d getLightColor() = 0;
    };
}
