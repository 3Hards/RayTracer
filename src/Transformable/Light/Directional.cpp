/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Directional
*/

#include "Directional.hpp"

Transformable::Light::Directional::Directional(Display::Color color, float brightness, Point3d pos, Point3d direction) : ALight(color, brightness, pos), _direction(direction)
{
}

Transformable::Point3d Transformable::Light::Directional::getLightDirection(std::shared_ptr<Raytracer::IVector>)
{
    return _direction;
}
