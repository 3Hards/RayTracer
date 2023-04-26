/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#pragma once

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
                virtual bool checkHit(std::unique_ptr<Raytracer::IVector>&) = 0;
                virtual Display::Color getColor() = 0;
                virtual std::shared_ptr<Raytracer::IVector> getNormalVector() = 0;
        };
    }
}
