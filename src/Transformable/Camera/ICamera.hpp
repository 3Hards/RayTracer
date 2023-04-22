/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include "../ITransformable.hpp"

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                //virtual *** getVectors() = 0;
        };
    }
}
