/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "Ambiant.hpp"

Transformable::Light::Ambiant::Ambiant(Display::Color color, float brightness, Point3f pos) : ALight(color, brightness, pos)
{}

bool Transformable::Light::Ambiant::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3f vectorPos = vector->getPos();

    if (vectorPos.x >= _pos.x - 1 && vectorPos.x <= _pos.x + 1 && vectorPos.y >= _pos.y - 1 && vectorPos.y <= _pos.y + 1 && vectorPos.z >= _pos.z - 1 && vectorPos.z <= _pos.z + 1) {
        return true;
    }
    return false;
}
