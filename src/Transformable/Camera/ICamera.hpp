/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "ITransformable.hpp"

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                virtual std::vector<Point3d> computeAxis() = 0;
                virtual unsigned int getWidth() const = 0;
                virtual unsigned int getHeight() const = 0;
        };
    }
}
