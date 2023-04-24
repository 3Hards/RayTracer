/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "Vector.hpp"
#include "Scene.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Scene::Scene scene;
    std::shared_ptr<Transformable::Camera::Camera> camera = std::make_shared<Transformable::Camera::Camera>({0, 0, 0}, {42, 0, 42}, 1920, 1080, 90);
    std::shared_ptr<Transformable::Primitive::>
    scene.addCamera(camera);
    return 0;
}
