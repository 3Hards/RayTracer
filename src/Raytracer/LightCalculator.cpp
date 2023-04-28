/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightCalculator header
*/

#include <exception>
#include <cmath>
#include "LightCalculator.hpp"
#include "Vector.hpp"

Raytracer::LightCalculator::LightCalculator(std::shared_ptr<IVector> vector, std::shared_ptr<Transformable::Light::ILight> light) : _vector(vector), _light(light)
{}

Display::Color Raytracer::LightCalculator::computePixel()
{
    return _vector->computeColor(_light);
}
