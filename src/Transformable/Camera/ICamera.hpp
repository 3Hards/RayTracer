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
                virtual Point3d computeAxis(int x, int y) = 0;
                virtual unsigned int getWidth() const = 0;
                virtual unsigned int getHeight() const = 0;
        };
    }
}
