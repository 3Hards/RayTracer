/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** Sphere
*/

#include <cmath>
#include "Sphere.hpp"

Transformable::Primitive::Sphere::Sphere(Point3f pos, float _ray, Material::IMaterial material) : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _ray(_ray)
{
}

//function that check if the vector hit the sphere
std::tuple<bool, Display::Color> Transformable::Primitive::Sphere::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3f vectorPos = vector->getPos();
    float distance = sqrt(pow(vectorPos.x - _pos.x, 2) + pow(vectorPos.y - _pos.y, 2) + pow(vectorPos.z - _pos.z, 2));

    if (distance <= _ray) {
        return std::make_tuple(true, Display::Color{1, 1, 1});
    }
    return std::make_tuple(false, Display::Color{0, 0, 0});
}
