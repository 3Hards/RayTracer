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
        App(std::vector<std::string> args);
        int run();
    private:
        void incrementPathId();

        std::vector<std::string> _args;
        int _pathId;
};
