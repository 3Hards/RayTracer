/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LibGraphicHandler
*/

#include <filesystem>
#include <fstream>
#include "LibGraphicHandler.hpp"

namespace Display {
    LibGraphicHandler::LibGraphicHandler(std::string fileName, unsigned int width, unsigned int height) :
        _fileName(fileName),
        _width(width),
        _height(height)
    {
        _image.create(_width, _height, sf::Color::Black);
    }

    const std::unordered_map<sf::Keyboard::Key, Display::Event> _keyboardMappings = {
        {sf::Keyboard::Num1, Event::KEYBOARD_1_PRESSED},
        {sf::Keyboard::Num2, Event::KEYBOARD_2_PRESSED},
        {sf::Keyboard::Num3, Event::KEYBOARD_3_PRESSED},
        {sf::Keyboard::Num4, Event::KEYBOARD_4_PRESSED},
        {sf::Keyboard::Num5, Event::KEYBOARD_5_PRESSED},
        {sf::Keyboard::Num6, Event::KEYBOARD_6_PRESSED},
        {sf::Keyboard::Num7, Event::KEYBOARD_7_PRESSED},
        {sf::Keyboard::Num8, Event::KEYBOARD_8_PRESSED},
        {sf::Keyboard::Num9, Event::KEYBOARD_9_PRESSED},
        {sf::Keyboard::Num0, Event::KEYBOARD_0_PRESSED},
        {sf::Keyboard::A, Event::KEYBOARD_A_PRESSED},
        {sf::Keyboard::B, Event::KEYBOARD_B_PRESSED},
        {sf::Keyboard::C, Event::KEYBOARD_C_PRESSED},
        {sf::Keyboard::D, Event::KEYBOARD_D_PRESSED},
        {sf::Keyboard::E, Event::KEYBOARD_E_PRESSED},
        {sf::Keyboard::F, Event::KEYBOARD_F_PRESSED},
        {sf::Keyboard::G, Event::KEYBOARD_G_PRESSED},
        {sf::Keyboard::H, Event::KEYBOARD_H_PRESSED},
        {sf::Keyboard::I, Event::KEYBOARD_I_PRESSED},
        {sf::Keyboard::J, Event::KEYBOARD_J_PRESSED},
        {sf::Keyboard::K, Event::KEYBOARD_K_PRESSED},
        {sf::Keyboard::L, Event::KEYBOARD_L_PRESSED},
        {sf::Keyboard::M, Event::KEYBOARD_M_PRESSED},
        {sf::Keyboard::N, Event::KEYBOARD_N_PRESSED},
        {sf::Keyboard::O, Event::KEYBOARD_O_PRESSED},
        {sf::Keyboard::P, Event::KEYBOARD_P_PRESSED},
        {sf::Keyboard::Q, Event::KEYBOARD_Q_PRESSED},
        {sf::Keyboard::R, Event::KEYBOARD_R_PRESSED},
        {sf::Keyboard::S, Event::KEYBOARD_S_PRESSED},
        {sf::Keyboard::T, Event::KEYBOARD_T_PRESSED},
        {sf::Keyboard::U, Event::KEYBOARD_U_PRESSED},
        {sf::Keyboard::V, Event::KEYBOARD_V_PRESSED},
        {sf::Keyboard::W, Event::KEYBOARD_W_PRESSED},
        {sf::Keyboard::X, Event::KEYBOARD_X_PRESSED},
        {sf::Keyboard::Y, Event::KEYBOARD_Y_PRESSED},
        {sf::Keyboard::Z, Event::KEYBOARD_Z_PRESSED},
        {sf::Keyboard::Up, Event::KEYBOARD_UP_PRESSED},
        {sf::Keyboard::Down, Event::KEYBOARD_DOWN_PRESSED},
        {sf::Keyboard::Left, Event::KEYBOARD_LEFT_PRESSED},
        {sf::Keyboard::Right, Event::KEYBOARD_RIGHT_PRESSED},
        {sf::Keyboard::Space, Event::KEYBOARD_SPACE_PRESSED},
        {sf::Keyboard::Enter, Event::KEYBOARD_ENTER_PRESSED},
        {sf::Keyboard::BackSpace, Event::KEYBOARD_BACKSPACE_PRESSED},
        {sf::Keyboard::Tab, Event::KEYBOARD_TAB_PRESSED},
        {sf::Keyboard::Escape, Event::KEYBOARD_ESCAPE_PRESSED},
        {sf::Keyboard::LShift, Event::KEYBOARD_SHIFT_PRESSED},
        {sf::Keyboard::LControl, Event::KEYBOARD_CTRL_PRESSED},
        {sf::Keyboard::LAlt, Event::KEYBOARD_ALT_PRESSED}
    };

    void LibGraphicHandler::addPixelToBuffer(Pixel pixel)
    {
        _image.setPixel(
            (unsigned int)pixel._pos._x,
            (unsigned int)pixel._pos._y,
            sf::Color(
                (sf::Uint8)pixel._color._r,
                (sf::Uint8)pixel._color._g,
                (sf::Uint8)pixel._color._b
            )
        );
    }

    void LibGraphicHandler::saveToPPM(std::string _filePath)
    {
        std::ofstream file(_filePath);

        file << "P3" << std::endl;
        file << _width << " " << _height << std::endl;
        file << "255" << std::endl;
        for (unsigned int y = 0; y < _height; y++) {
            for (unsigned int x = 0; x < _width; x++) {
                sf::Color color = _image.getPixel(x, y);
                file << (int)color.r << " " << (int)color.g << " " << (int)color.b << " ";
            }
            file << std::endl;
        }
        file.close();
    }

    void LibGraphicHandler::exportImage()
    {
        if (folderChecker() == true) {
            std::string _filePath = "./screenshots/" + _fileName + ".ppm";
            saveToPPM(_filePath);
        }
    }

    void LibGraphicHandler::closeWindow()
    {
        if (_window.isOpen()) {
            _window.close();
        }
    }

    void LibGraphicHandler::createWindow(const std::string &name, unsigned int width, unsigned int height)
    {
        _window.create(sf::VideoMode(width, height), name, sf::Style::Default);
    }

    bool LibGraphicHandler::isWindowOpen()
    {
        return _window.isOpen();
    }

    void LibGraphicHandler::resizeWindow(unsigned int width, unsigned int height)
    {
        _width = width;
        _height = height;
        _window.setSize(sf::Vector2u(_width, _height));
        _image.create(width, height, sf::Color::Black);
    }

    void LibGraphicHandler::refreshWindow()
    {
        clearWindow();
        _texture.loadFromImage(_image);
        _sprite.setTexture(_texture);
        _window.draw(_sprite);
        _window.display();
    }

    std::pair<unsigned int, unsigned int> LibGraphicHandler::getWindowSize()
    {
        return std::make_pair(_width, _height);
    }

    void LibGraphicHandler::checkKeyboardEvents()
    {
        for (auto &keyboardMapping : _keyboardMappings) {
            if (sf::Keyboard::isKeyPressed(keyboardMapping.first)) {
                _events.push_back(keyboardMapping.second);
            }
        }
    }

    void LibGraphicHandler::checkOtherEvents()
    {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
            }
            if (_event.type == sf::Event::Resized) {
                resizeWindow(_event.size.width, _event.size.height);
                _events.push_back(Event::WINDOW_RESIZED);
            }
            if (_event.type == sf::Event::Closed) {
                _events.push_back(Event::WINDOW_CLOSED);
            }
        }
    }

    std::vector<Event> LibGraphicHandler::getEvents()
    {
        _events.clear();
        checkKeyboardEvents();
        checkOtherEvents();
        return _events;
    }

    void LibGraphicHandler::clearWindow()
    {
        _window.clear(sf::Color::Black);
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
