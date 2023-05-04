/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AMaterial
*/

#include <cmath>
#include "AMaterial.hpp"

Material::AMaterial::AMaterial(Display::Color color, double shininess, double reflection) : _shininess(shininess), _reflection(reflection)
{
    _baseColor.x = color._r / 255;
    _baseColor.y = color._g / 255;
    _baseColor.z = color._b / 255;
}

Transformable::Point3d Material::AMaterial::getBaseColor()
{
    return _baseColor;
}

Transformable::Point3d Material::AMaterial::computeSpecular(std::shared_ptr<Raytracer::IVector> vector)
{
    if (_reflection == 0) {
        return {0, 0, 0};
    }

    double specularFactor = std::pow(std::max(vector->getScalarRI(), (double)0), _shininess);
    Transformable::Point3d lightColor = vector->getLightColor();
    Transformable::Point3d specularColor = {_baseColor.x * _reflection, _baseColor.y * _reflection, _baseColor.z * _reflection};

    return {lightColor.x * specularColor.x * specularFactor, lightColor.y * specularColor.y * specularFactor, lightColor.z * specularColor.z * specularFactor};
}
