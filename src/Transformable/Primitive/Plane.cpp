/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** Plane
*/

#include <cmath>
#include "Plane.hpp"

#include <iostream>

Transformable::Primitive::Plane::Plane(Point3f pos, double length, double width, std::shared_ptr<Material::IMaterial> material)
    : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _length(length), _width(width)
{
    _depth = 1;
}

std::tuple<bool, Display::Color> Transformable::Primitive::Plane::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3f vectorPos = vector->getPos();

    double distanceX = fabs(vectorPos.x - _pos.x);
    double distanceY = fabs(vectorPos.y - _pos.y);
    double distanceZ = fabs(vectorPos.z - _pos.z);

    if (distanceX <= (_length / 2) &&
        distanceY <= (_width / 2) &&
        distanceZ <= (_depth / 2)) {
        std::cout << "TROUVE COPAIN" << std::endl;
        return std::make_tuple(true, _material->getColor(vector));
    } else {
        return std::make_tuple(false, Display::Color{0, 0, 0});
    }
}
