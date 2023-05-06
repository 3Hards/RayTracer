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
            virtual Display::Color computeColor() = 0;
            virtual double getScalarRI() = 0;
            virtual Transformable::Point3d getLightColor() = 0;
    };
}
