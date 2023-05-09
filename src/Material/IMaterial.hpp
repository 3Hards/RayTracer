/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IVector
*/

#pragma once

#include "IVector.hpp"
#include "DisplayStructs.hpp"

namespace Material {
    class IMaterial {
        public:
            virtual Transformable::Point3d getBaseColor() = 0;
            virtual Transformable::Point3d computeSpecular(std::shared_ptr<Raytracer::IVector>) = 0;
    };
}
