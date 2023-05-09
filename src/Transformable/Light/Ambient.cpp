/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "Ambient.hpp"
#include <cmath>

Transformable::Light::Ambient::Ambient(Display::Color color, float brightness, Point3d pos) : ALight(color, brightness, pos)
{}

bool Transformable::Light::Ambient::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    (void)vector;
    return true;
}
