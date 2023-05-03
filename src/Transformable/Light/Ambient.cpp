/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "Ambient.hpp"
#include <cmath>
//see later
double ddot(Transformable::Point3d a, Transformable::Point3d b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Transformable::Light::Ambient::Ambient(Display::Color color, float brightness, Point3d pos) : ALight(color, brightness, pos)
{}

bool Transformable::Light::Ambient::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    (void)vector;
    return true;
}
