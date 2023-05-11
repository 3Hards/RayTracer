/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILibGraphicHandler
*/

#pragma once

#include <vector>
#include <utility>
#include "DisplayStructs.hpp"

namespace Display {

    /**
     * @brief Enum of all the events that can be triggered
    */
    enum class Event {
        //MOUSE EVENTS
        MOUSE_LEFT_PRESSED,
        MOUSE_RIGHT_PRESSED,
        //KEYBOARD NUMBERS
        KEYBOARD_1_PRESSED,
        KEYBOARD_2_PRESSED,
        KEYBOARD_3_PRESSED,
        KEYBOARD_4_PRESSED,
        KEYBOARD_5_PRESSED,
        KEYBOARD_6_PRESSED,
        KEYBOARD_7_PRESSED,
        KEYBOARD_8_PRESSED,
        KEYBOARD_9_PRESSED,
        KEYBOARD_0_PRESSED,
        //KEYBOARD LETTERS
        KEYBOARD_A_PRESSED,
        KEYBOARD_B_PRESSED,
        KEYBOARD_C_PRESSED,
        KEYBOARD_D_PRESSED,
        KEYBOARD_E_PRESSED,
        KEYBOARD_F_PRESSED,
        KEYBOARD_G_PRESSED,
        KEYBOARD_H_PRESSED,
        KEYBOARD_I_PRESSED,
        KEYBOARD_J_PRESSED,
        KEYBOARD_K_PRESSED,
        KEYBOARD_L_PRESSED,
        KEYBOARD_M_PRESSED,
        KEYBOARD_N_PRESSED,
        KEYBOARD_O_PRESSED,
        KEYBOARD_P_PRESSED,
        KEYBOARD_Q_PRESSED,
        KEYBOARD_R_PRESSED,
        KEYBOARD_S_PRESSED,
        KEYBOARD_T_PRESSED,
        KEYBOARD_U_PRESSED,
        KEYBOARD_V_PRESSED,
        KEYBOARD_W_PRESSED,
        KEYBOARD_X_PRESSED,
        KEYBOARD_Y_PRESSED,
        KEYBOARD_Z_PRESSED,
        //KEYBOARD ARROWS
        KEYBOARD_UP_PRESSED,
        KEYBOARD_DOWN_PRESSED,
        KEYBOARD_LEFT_PRESSED,
        KEYBOARD_RIGHT_PRESSED,
        //KEYBOARD SPECIALS
        KEYBOARD_SPACE_PRESSED,
        KEYBOARD_ENTER_PRESSED,
        KEYBOARD_BACKSPACE_PRESSED,
        KEYBOARD_TAB_PRESSED,
        KEYBOARD_ESCAPE_PRESSED,
        KEYBOARD_SHIFT_PRESSED,
        KEYBOARD_CTRL_PRESSED,
        KEYBOARD_ALT_PRESSED,
        //EVENTS
        WINDOW_CLOSED,
        WINDOW_RESIZED
    };

    /**
     * @brief Interface of the graphic handler
    */
    class ILibGraphicHandler {
        public:

            /**
             * @brief add a pixel to the buffer
             * @param pixel is the pixel to add
             * @return void
            */
            virtual void addPixelToBuffer(Pixel pixel) = 0;

            /**
             * @brief export the image
             * @return void
            */
            virtual void exportImage() = 0;

            /**
             * @brief close the window
             * @return void
            */
            virtual void closeWindow() = 0;

            /**
             * @brief create the window
             * @param name is the name of the window
             * @param width is the width of the window
             * @param height is the height of the window
             * @return void
            */
            virtual void createWindow(const std::string &name, unsigned int width, unsigned int height) = 0;

            /**
             * @brief refresh the window
             * @return void
            */
            virtual void refreshWindow() = 0;

            /**
             * @brief resize the window
             * @param width is the width of the window
             * @param height is the height of the window
             * @return void
            */
            virtual void resizeWindow(unsigned int width, unsigned int height) = 0;

            /**
             * @brief check if the window is open
             * @return true if the window is open, false otherwise
            */
            virtual bool isWindowOpen() = 0;

            /**
             * @brief get the events
             * @return a vector of events
            */
            virtual std::vector<Event> getEvents() = 0;

            /**
             * @brief get the window size
             * @return a pair of unsigned int
            */
            virtual std::pair<unsigned int, unsigned int> getWindowSize() = 0;
    };
}
