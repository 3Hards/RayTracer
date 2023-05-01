/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "Ambient.hpp"

Transformable::Light::Ambient::Ambient(Display::Color color, float brightness, Point3d pos) : ALight(color, brightness, pos)
{}

bool Transformable::Light::Ambient::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3d vectorPos = vector->getPos();

    if (vectorPos.x >= _pos.x - 1 && vectorPos.x <= _pos.x + 1 && vectorPos.y >= _pos.y - 1 && vectorPos.y <= _pos.y + 1 && vectorPos.z >= _pos.z - 1 && vectorPos.z <= _pos.z + 1) {
        return true;
    }
    return false;
}
