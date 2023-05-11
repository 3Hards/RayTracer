/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** App
*/

#include <iostream>
#include "App.hpp"
#include "Director.hpp"

App::App(std::vector<std::string> args) : _args(args), _pathId(0)
{}

void App::incrementPathId()
{
    if (_pathId == (int)_args.size() - 1) {
        _pathId = 0;
    } else {
        _pathId += 1;
    }
}

int App::run()
{
    if (_args.size() < 1) {
        std::cerr << "Usage: ./raytracer [config_file]" << std::endl;
        return 84;
    }
    try {
        Scene::Director director(_args[0]);
        while (director.playScene()) {
            incrementPathId();
            director = Scene::Director(_args[_pathId]);
        }
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
