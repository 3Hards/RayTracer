/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Ambient.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Director.hpp"
#include "FlatColor.hpp"
#include "Translation.hpp"

int main()
{

    Scene::Director director(std::string("test"));
    director.playScene();

    return 0;
}