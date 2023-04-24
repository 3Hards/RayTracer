/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "IVector.hpp"
#include "DisplayStructs.hpp"
#include "Sphere.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    Transformable::Primitive::Sphere sphere({250, 0, 0}, 1.0, Material::IMaterial{});
    return 0;
}
