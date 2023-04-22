/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "../ITransformable.hpp"

namespace Raytracer {
    class IVector;
}

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                virtual std::vector<Raytracer::IVector> getVectors() const = 0;
        };
    }
}
