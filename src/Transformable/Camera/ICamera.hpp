/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "IVector.hpp"
#include "ITransformable.hpp"

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                virtual void render(std::shared_ptr<Raytracer::IVector> vector, std::string fileName) = 0;
                virtual void render(std::shared_ptr<Raytracer::IVector> vector) = 0;
        };
    }
}
