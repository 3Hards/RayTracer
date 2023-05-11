/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Ambient
*/

#include "Ambient.hpp"
#include <cmath>

Transformable::Light::Ambient::Ambient(Display::Color color, float brightness, Point3d pos) : ALight(color, brightness, pos)
{}

Transformable::Point3d Transformable::Light::Ambient::getLightDirection(std::shared_ptr<Raytracer::IVector> vector)
{
    return vector->getAxis();
}
