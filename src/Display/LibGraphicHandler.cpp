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
        _window.setSize(sf::Vector2u(width, height));
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

    std::vector<Event> LibGraphicHandler::getEvents()
    {
        std::vector<Event> events;

        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed) {
                _window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
                events.push_back(Event::KEYBORD_1_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
                events.push_back(Event::KEYBORD_2_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
                events.push_back(Event::KEYBORD_3_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
                events.push_back(Event::KEYBORD_4_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num5)) {
                events.push_back(Event::KEYBORD_5_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num6)) {
                events.push_back(Event::KEYBORD_6_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num7)) {
                events.push_back(Event::KEYBORD_7_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num8)) {
                events.push_back(Event::KEYBORD_8_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num9)) {
                events.push_back(Event::KEYBORD_9_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
                events.push_back(Event::KEYBORD_0_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                events.push_back(Event::KEYBORD_A_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
                events.push_back(Event::KEYBORD_B_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
                events.push_back(Event::KEYBORD_C_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                events.push_back(Event::KEYBORD_D_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
                events.push_back(Event::KEYBORD_E_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
                events.push_back(Event::KEYBORD_F_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
                events.push_back(Event::KEYBORD_G_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
                events.push_back(Event::KEYBORD_H_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                events.push_back(Event::KEYBORD_I_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                events.push_back(Event::KEYBORD_J_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                events.push_back(Event::KEYBORD_K_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                events.push_back(Event::KEYBORD_L_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
                events.push_back(Event::KEYBORD_M_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
                events.push_back(Event::KEYBORD_N_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
                events.push_back(Event::KEYBORD_O_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
                events.push_back(Event::KEYBORD_P_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                events.push_back(Event::KEYBORD_Q_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                events.push_back(Event::KEYBORD_R_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                events.push_back(Event::KEYBORD_S_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
                events.push_back(Event::KEYBORD_T_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
                events.push_back(Event::KEYBORD_U_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
                events.push_back(Event::KEYBORD_V_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                events.push_back(Event::KEYBORD_W_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
                events.push_back(Event::KEYBORD_X_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
                events.push_back(Event::KEYBORD_Y_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                events.push_back(Event::KEYBORD_Z_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
                events.push_back(Event::KEYBORD_UP_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
                events.push_back(Event::KEYBORD_DOWN_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                events.push_back(Event::KEYBORD_LEFT_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                events.push_back(Event::KEYBORD_RIGHT_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                events.push_back(Event::KEYBORD_SPACE_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
                events.push_back(Event::KEYBORD_ENTER_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
                events.push_back(Event::KEYBORD_BACKSPACE_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) {
                events.push_back(Event::KEYBORD_TAB_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                events.push_back(Event::KEYBORD_ESCAPE_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                events.push_back(Event::KEYBORD_SHIFT_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
                events.push_back(Event::KEYBORD_CTRL_PRESSED);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt)) {
                events.push_back(Event::KEYBORD_ALT_PRESSED);
            }
        }
        return events;
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
