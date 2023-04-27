/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LibGraphicHandler
*/

#pragma once

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include "ILibGraphicHandler.hpp"

namespace Display {
    class LibGraphicHandler : public ILibGraphicHandler {
        public:
            LibGraphicHandler(std::string fileName, unsigned int width, unsigned int height);
            void exportImage() final;
            void addPixelToImage(Pixel pixel) final;
        private:
            bool folderChecker();
            std::string _fileName;
            sf::Image _image;
            unsigned int _width;
            unsigned int _height;
    };
}
