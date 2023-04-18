/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#include "Vector.hpp"

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>> primitives)
{
    _primitives = primitives;
}

void Raytracer::Vector::moveForward()
{

}

std::tuple<bool, Material::IMaterial, Transformable::Point3f> Raytracer::Vector::checkHit()
{
    for (auto primitive : _primitives) {
        primitive
    }
}

std::tuple<bool, Material::IMaterial, Transformable::Point3f> Raytracer::Vector::run(Transformable::ILight)
{
    std::tuple<bool, Material::IMaterial, Transformable::Point3f> res = checkHit();

    if (std::get<0>(res) == true) {
        return res;
    }
    moveForward();
    return res;
}
