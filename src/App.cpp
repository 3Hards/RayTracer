/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** App
*/

#include "App.hpp"
#include "Director.hpp"

int App::run(char **arguments)
{
    if (arguments == NULL || arguments[1] == NULL) {
        return 84;
    }
    try {
        Scene::Director director(arguments[1]);
        director.playScene();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
