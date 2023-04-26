/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LibGraphicHandler
*/

#include <filesystem>
#include "LibGraphicHandler.hpp"

namespace Display {
    LibGraphicHandler::LibGraphicHandler(std::string fileName, unsigned int width, unsigned int height) :
        _fileName(fileName),
        _width(width),
        _height(height)
    {}

    void LibGraphicHandler::createImage(std::vector<Pixel> pixels)
    {
        _image.create(_width, _height, sf::Color::Black);
        for (auto pixel : pixels) {
            _image.setPixel(
                (unsigned int)pixel._pos._x,
                pixel._pos._y,
                sf::Color(
                    (sf::Uint8)pixel._color._r,
                    (sf::Uint8)pixel._color._g,
                    (sf::Uint8)pixel._color._b
                )
            );
        }
        exportImage();
    }

    void LibGraphicHandler::exportImage()
    {
        if (folderChecker() == true) {
            std::string _filePath = "./screenshots/" + _fileName + ".png";
            _image.saveToFile(_filePath);
        }
    }

    bool LibGraphicHandler::folderChecker()
    {
        if (std::filesystem::exists("./screenshots")) {
            return true;
        }
        if (std::filesystem::create_directory("./screenshots")) {
            return true;
        } else {
            return false;
        }
    }
}
