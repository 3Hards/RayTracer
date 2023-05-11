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
        //KEYBORD NUMBERS
        KEYBORD_1_PRESSED,
        KEYBORD_2_PRESSED,
        KEYBORD_3_PRESSED,
        KEYBORD_4_PRESSED,
        KEYBORD_5_PRESSED,
        KEYBORD_6_PRESSED,
        KEYBORD_7_PRESSED,
        KEYBORD_8_PRESSED,
        KEYBORD_9_PRESSED,
        KEYBORD_0_PRESSED,
        //KEYBORD LETTERS
        KEYBORD_A_PRESSED,
        KEYBORD_B_PRESSED,
        KEYBORD_C_PRESSED,
        KEYBORD_D_PRESSED,
        KEYBORD_E_PRESSED,
        KEYBORD_F_PRESSED,
        KEYBORD_G_PRESSED,
        KEYBORD_H_PRESSED,
        KEYBORD_I_PRESSED,
        KEYBORD_J_PRESSED,
        KEYBORD_K_PRESSED,
        KEYBORD_L_PRESSED,
        KEYBORD_M_PRESSED,
        KEYBORD_N_PRESSED,
        KEYBORD_O_PRESSED,
        KEYBORD_P_PRESSED,
        KEYBORD_Q_PRESSED,
        KEYBORD_R_PRESSED,
        KEYBORD_S_PRESSED,
        KEYBORD_T_PRESSED,
        KEYBORD_U_PRESSED,
        KEYBORD_V_PRESSED,
        KEYBORD_W_PRESSED,
        KEYBORD_X_PRESSED,
        KEYBORD_Y_PRESSED,
        KEYBORD_Z_PRESSED,
        //KEYBORD ARROWS
        KEYBORD_UP_PRESSED,
        KEYBORD_DOWN_PRESSED,
        KEYBORD_LEFT_PRESSED,
        KEYBORD_RIGHT_PRESSED,
        //KEYBORD SPECIALS
        KEYBORD_SPACE_PRESSED,
        KEYBORD_ENTER_PRESSED,
        KEYBORD_BACKSPACE_PRESSED,
        KEYBORD_TAB_PRESSED,
        KEYBORD_ESCAPE_PRESSED,
        KEYBORD_SHIFT_PRESSED,
        KEYBORD_CTRL_PRESSED,
        KEYBORD_ALT_PRESSED,
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
