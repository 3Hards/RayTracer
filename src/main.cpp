/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "Transformable/Camera/Camera.hpp"
#include "Scene.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Transformable::Camera::Camera camera({0, 0, 0}, {42, 0, 42}, 1920, 1080, 90);
    Scene::Scene scene;
    return 0;
}
