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
    enum class HittedObject {
        UNDEFINED,
        VOID,
        PRIMITIVE,
        LIGHT
    };

    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;
            virtual void run(std::shared_ptr<Transformable::Light::ILight> light) = 0;
            virtual HittedObject getHittedObject() = 0;
            virtual Display::Color getHittedColor() = 0;
    };
}
