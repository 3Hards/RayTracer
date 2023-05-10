/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** App
*/

#include <iostream>
#include <list>
#include "App.hpp"
#include "Director.hpp"

int App::run(std::list<std::string> args)
{
    if (args.size() != 1) {
        std::cerr << "Usage: ./raytracer [config_file]" << std::endl;
        return 84;
    }
    try {
        Scene::Director director(args.back());
        director.playScene();
        return 0;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
}
