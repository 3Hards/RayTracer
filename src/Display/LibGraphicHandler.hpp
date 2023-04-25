/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LibGraphicHandler
*/

#pragma once

#include <vector>
#include <string>
#include <sfml/Graphics.hpp>
#include "ILibGraphicHandler.hpp"

namespace Display {
    class LibGraphicHandler : public ILibGraphicHandler {
        public:
            LibGraphicHandler(std::string fileName);
            void createImage(std::vector<Pixel> pixels) final;
        private:
            void exportImage();
            bool folderChecker();
            std::string _fileName;
            sf::Image _image;
    };
}
