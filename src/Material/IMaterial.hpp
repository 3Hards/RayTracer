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
            virtual Display::Color getColor(std::unique_ptr<Raytracer::IVector>&) = 0;
    };
}
