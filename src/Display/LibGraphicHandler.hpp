/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LibGraphicHandler
*/

#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "ILibGraphicHandler.hpp"

namespace Display {
    class LibGraphicHandler : public ILibGraphicHandler {
        public:
            LibGraphicHandler(std::string fileName, unsigned int width, unsigned int height);
            void exportImagePPM()final;
            void exportImagePNG() final;
            void addPixelToBuffer(Pixel pixel) final;
            void closeWindow() final;
            void createWindow(const std::string &name, unsigned int width, unsigned int height);
            void refreshWindow();
            void resizeWindow(unsigned int width, unsigned int height);
            bool isWindowOpen() final;
            std::vector<Event> getEvents();
            std::pair<unsigned int, unsigned int> getWindowSize() final;

        private:
            std::string extractFileName();
            void clearWindow();
            bool folderChecker();
            void checkKeyboardEvents();
            void checkOtherEvents();
            void saveToPPM(std::string _filePath);
            std::string _fileName;
            sf::Image _image;
            sf::RenderWindow _window;
            sf::Texture _texture;
            sf::Sprite _sprite;
            sf::Event _event;
            unsigned int _width;
            unsigned int _height;
            std::vector<Display::Event> _events;
    };
}
