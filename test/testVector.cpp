/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#include "Vector.hpp"
#include <iostream>

int main(void)
{
    std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> list;
    Raytracer::Vector vector({0, 0, 0}, {0, 0, 1});
    Transformable::Light::ILight light;

    vector.setPrimitives(list);
    Transformable::Point3d pos = vector.getPos();
    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    vector.run(light);
    pos = vector.getPos();
    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
}
