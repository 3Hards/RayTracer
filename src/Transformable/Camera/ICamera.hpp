/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "../ITransformable.hpp"
#include "../../Raytracer/IVector.hpp"

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                virtual std::vector<std::shared_ptr<Raytracer::IVector>> getVectors() const = 0;
        };
    }
}
