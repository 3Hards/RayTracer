/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILibGraphicHandler
*/

#pragma once

#include <vector>
#include "DisplayStructs.hpp"

namespace Display {
    class ILibGraphicHandler {
        public:
            virtual void addPixelToImage(Pixel pixel) = 0;
            virtual void exportImage() = 0;
    };
}
