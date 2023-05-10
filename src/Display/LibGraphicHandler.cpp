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
    {
        _image.create(_width, _height, sf::Color::Black);
        bindEvent();
    }

    void LibGraphicHandler::bindEvent()
    {
        _keyboardMappings[sf::Keyboard::Num1] = Event::KEYBORD_1_PRESSED;
        _keyboardMappings[sf::Keyboard::Num2] = Event::KEYBORD_2_PRESSED;
        _keyboardMappings[sf::Keyboard::Num3] = Event::KEYBORD_3_PRESSED;
        _keyboardMappings[sf::Keyboard::Num4] = Event::KEYBORD_4_PRESSED;
        _keyboardMappings[sf::Keyboard::Num5] = Event::KEYBORD_5_PRESSED;
        _keyboardMappings[sf::Keyboard::Num6] = Event::KEYBORD_6_PRESSED;
        _keyboardMappings[sf::Keyboard::Num7] = Event::KEYBORD_7_PRESSED;
        _keyboardMappings[sf::Keyboard::Num8] = Event::KEYBORD_8_PRESSED;
        _keyboardMappings[sf::Keyboard::Num9] = Event::KEYBORD_9_PRESSED;
        _keyboardMappings[sf::Keyboard::Num0] = Event::KEYBORD_0_PRESSED;
        _keyboardMappings[sf::Keyboard::A] = Event::KEYBORD_A_PRESSED;
        _keyboardMappings[sf::Keyboard::B] = Event::KEYBORD_B_PRESSED;
        _keyboardMappings[sf::Keyboard::C] = Event::KEYBORD_C_PRESSED;
        _keyboardMappings[sf::Keyboard::D] = Event::KEYBORD_D_PRESSED;
        _keyboardMappings[sf::Keyboard::E] = Event::KEYBORD_E_PRESSED;
        _keyboardMappings[sf::Keyboard::F] = Event::KEYBORD_F_PRESSED;
        _keyboardMappings[sf::Keyboard::G] = Event::KEYBORD_G_PRESSED;
        _keyboardMappings[sf::Keyboard::H] = Event::KEYBORD_H_PRESSED;
        _keyboardMappings[sf::Keyboard::I] = Event::KEYBORD_I_PRESSED;
        _keyboardMappings[sf::Keyboard::J] = Event::KEYBORD_J_PRESSED;
        _keyboardMappings[sf::Keyboard::K] = Event::KEYBORD_K_PRESSED;
        _keyboardMappings[sf::Keyboard::L] = Event::KEYBORD_L_PRESSED;
        _keyboardMappings[sf::Keyboard::M] = Event::KEYBORD_M_PRESSED;
        _keyboardMappings[sf::Keyboard::N] = Event::KEYBORD_N_PRESSED;
        _keyboardMappings[sf::Keyboard::O] = Event::KEYBORD_O_PRESSED;
        _keyboardMappings[sf::Keyboard::P] = Event::KEYBORD_P_PRESSED;
        _keyboardMappings[sf::Keyboard::Q] = Event::KEYBORD_Q_PRESSED;
        _keyboardMappings[sf::Keyboard::R] = Event::KEYBORD_R_PRESSED;
        _keyboardMappings[sf::Keyboard::S] = Event::KEYBORD_S_PRESSED;
        _keyboardMappings[sf::Keyboard::T] = Event::KEYBORD_T_PRESSED;
        _keyboardMappings[sf::Keyboard::U] = Event::KEYBORD_U_PRESSED;
        _keyboardMappings[sf::Keyboard::V] = Event::KEYBORD_V_PRESSED;
        _keyboardMappings[sf::Keyboard::W] = Event::KEYBORD_W_PRESSED;
        _keyboardMappings[sf::Keyboard::X] = Event::KEYBORD_X_PRESSED;
        _keyboardMappings[sf::Keyboard::Y] = Event::KEYBORD_Y_PRESSED;
        _keyboardMappings[sf::Keyboard::Z] = Event::KEYBORD_Z_PRESSED;
        _keyboardMappings[sf::Keyboard::Up] = Event::KEYBORD_UP_PRESSED;
        _keyboardMappings[sf::Keyboard::Down] = Event::KEYBORD_DOWN_PRESSED;
        _keyboardMappings[sf::Keyboard::Left] = Event::KEYBORD_LEFT_PRESSED;
        _keyboardMappings[sf::Keyboard::Right] = Event::KEYBORD_RIGHT_PRESSED;
        _keyboardMappings[sf::Keyboard::Space] = Event::KEYBORD_SPACE_PRESSED;
        _keyboardMappings[sf::Keyboard::Enter] = Event::KEYBORD_ENTER_PRESSED;
        _keyboardMappings[sf::Keyboard::BackSpace] = Event::KEYBORD_BACKSPACE_PRESSED;
        _keyboardMappings[sf::Keyboard::Tab] = Event::KEYBORD_TAB_PRESSED;
        _keyboardMappings[sf::Keyboard::Escape] = Event::KEYBORD_ESCAPE_PRESSED;
        _keyboardMappings[sf::Keyboard::LShift] = Event::KEYBORD_SHIFT_PRESSED;
        _keyboardMappings[sf::Keyboard::LControl] = Event::KEYBORD_CTRL_PRESSED;
        _keyboardMappings[sf::Keyboard::LAlt] = Event::KEYBORD_ALT_PRESSED;
    }

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

    void LibGraphicHandler::exportImage()
    {
        if (folderChecker() == true) {
            std::string _filePath = "./screenshots/" + _fileName + ".png";
            _image.saveToFile(_filePath);
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
