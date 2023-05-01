/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** FlatColor
*/

#include "FlatColor.hpp"

Material::FlatColor::FlatColor(Display::Color color) : _color(color)
{}

Display::Color Material::FlatColor::getColor(std::unique_ptr<Raytracer::IVector>&)
{
    return _color;
}
