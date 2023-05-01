/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILight
*/

#pragma once

#include <memory>
#include "DisplayStructs.hpp"
#include "IVector.hpp"
#include "ITransformable.hpp"

namespace Transformable {
    namespace Light {
        class ILight : public ITransformable {
            public:
                virtual ~ILight() = default;
                virtual bool checkHit(std::unique_ptr<Raytracer::IVector>&) = 0;
                virtual Transformable::Point3d getAmbientLightColor() = 0;
                virtual Transformable::Point3d getLightColor() = 0;
        };
    }
}
