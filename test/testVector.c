/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#include "Vector.hpp"

int main(void)
{
    std::vector<std::shared_ptr<Transformable::IPrimitive>> list;
    Raytracer::Vector vector;

    vector.setPrimitives(list);
}
