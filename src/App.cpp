/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** App
*/

#include "App.hpp"
#include "Director.hpp"

App::App()
{
}

App::~App()
{
}

int App::run(char **av)
{
    if (av[1] == NULL) return 84;
    try {
        Scene::Director director(av[1]);
        director.playScene();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}

