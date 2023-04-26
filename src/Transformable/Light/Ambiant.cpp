/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "Ambiant.hpp"

Transformable::Light::Ambiant::Ambiant(Display::Color color, float brightness, Point3f pos) : ALight(color, brightness, pos)
{}

std::tuple<bool, Display::Color> Transformable::Light::Ambiant::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3f vectorPos = vector->getPos();

    if (vectorPos.x == _pos.x && vectorPos.y == _pos.y && vectorPos.z == _pos.z) {
        return std::make_tuple(true, _color);
    }
    return std::make_tuple(false, Display::Color{0, 0, 0});
}
