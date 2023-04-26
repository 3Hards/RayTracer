/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** testSfml
*/

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Display/LibGraphicHandler.hpp"

int main()
{
    Display::LibGraphicHandler lib("test", 1200, 1200);
    std::vector<Display::Pixel> pixels;
    sf::Image image;

    if (!image.loadFromFile("./test/1200x1200.jpg")) {
        std::cout << "Error while loading image" << std::endl;
    }

    for (unsigned int x = 0; x < image.getSize().x; x++) {
        for (unsigned int y = 0; y < image.getSize().y; y++) {
            sf::Color color = image.getPixel(x, y);
            Display::Pixel pixel;
            pixel._color._r = color.r;
            pixel._color._g = color.g;
            pixel._color._b = color.b;
            pixel._pos._x = x;
            pixel._pos._y = y;
            pixels.push_back(pixel);
        }
    }
    lib.createImage(pixels);
    return 0;
}
