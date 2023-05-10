/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "App.hpp"

int main(int, char **av)
{
    App app;
    std::list<std::string> args;

    for (int i = 1; av[i]; i++)
        args.push_back(av[i]);
    return app.run(args);
}
