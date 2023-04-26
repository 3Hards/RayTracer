/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightCalculator header
*/

#include "LightCalculator.hpp"

Raytracer::LightCalculator::LightCalculator(std::shared_ptr<IVector> vector, std::shared_ptr<Transformable::Light::ILight> light) : _vector(vector), _light(light)
{}

std::unique_ptr<IVector> Raytracer::LightCalculator::getNewVector(Transformable::Point3f hitPos)
{
    Transformable::Point3f lightPos = _light.getPos();
    Transformable::Point3f axis{lightPos.x - hitPos.x, lightPos.y - hitPos.y, lightPos.z - hitPos.z};

    _vector.setPos(hitPos);
    _vector.setAxis(axis);
}

Display::Color Raytracer::LightCalculator::computePixel()
{
    std::tuple<bool, Display::Color, Transformable::Point3f> fstRes = _vector->run(light);

    if (std::get<1>(fstRes) == Display::Color{-1, -1, -1}) {
        return Display::Color{0, 0, 0};
    }
    getNewVector(std::get<2>(res));
    std::tuple<bool, Display::Color, Transformable::Point3f> scdRes = _vector->run(light);
    
}
