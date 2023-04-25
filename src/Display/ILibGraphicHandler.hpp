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
            virtual void createImage(std::vector<Pixel> pixels) = 0;
    };
}
