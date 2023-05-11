/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** App
*/

#pragma once

#include <vector>
#include "Director.hpp"

class App {
    public:

        /**
         * @brief Run the app
         * @param args
         * @return int
        */
        int run(std::list<std::string> args);
        App(std::vector<std::string> args);
    private:
        void incrementPathId();
        std::vector<std::string> _args;
        int _pathId;
};
