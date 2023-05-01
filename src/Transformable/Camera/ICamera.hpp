/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "ITransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                virtual std::vector<std::shared_ptr<Raytracer::IVector>> computeVectors() = 0;
                virtual unsigned int getWidth() const = 0;
                virtual unsigned int getHeight() const = 0;
        };
    }
}
