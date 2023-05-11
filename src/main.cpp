/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "App.hpp"

int main(int, char **av)
{
    std::vector<std::string> args;

    for (int i = 1; av[i]; i++)
        args.push_back(av[i]);
    App app(args);
    return app.run();
}
