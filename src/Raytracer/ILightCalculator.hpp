/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILightCalculator
*/

#pragma once

#include "DisplayStructs.hpp"

namespace Raytracer {
    class ILightCalculator {
        virtual Display::Color computePixel() = 0;
    };
}
