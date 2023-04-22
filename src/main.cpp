/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "Transformable/Camera/Camera.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Transformable::Camera::Camera camera(90, 1920, 1080, {0, 0, 0}, {0, 0, 0});
    return 0;
}
