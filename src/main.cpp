/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Ambient.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "FlatColor.hpp"
#include "Translation.hpp"
#include <iostream>
#include "Rotation.hpp"
#include "Director.hpp"

int main()
{
    Scene::Director director("Config/test.cfg");
    director.playScene();
    return 0;
}
