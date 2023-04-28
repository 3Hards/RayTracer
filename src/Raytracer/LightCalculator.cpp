/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightCalculator header
*/

#include <exception>
#include <cmath>
#include "LightCalculator.hpp"

Raytracer::LightCalculator::LightCalculator(std::shared_ptr<IVector> vector, std::shared_ptr<Transformable::Light::ILight> light) : _vector(vector), _light(light), _incident({0, 0, 0})
{}

void Raytracer::LightCalculator::redirectVector()
{
    Transformable::Point3f hitPos = _vector->getPos();
    Transformable::Point3f lightPos = _light->getPos();
    Transformable::Point3f axis{lightPos.x - hitPos.x, lightPos.y - hitPos.y, lightPos.z - hitPos.z};

    _vector->toLight();
    _vector->setAxis(axis);
}

double Raytracer::LightCalculator::computeScalarProduct(Transformable::Point3f fst, Transformable::Point3f scd)
{
    return fst.x * scd.x + fst.y * scd.y + fst.z * scd.z;
}

Display::Color Raytracer::LightCalculator::compute()
{
    std::shared_ptr<IVector> normalVector = _vector->getHittedNormalVector();
    Transformable::Point3f normalAxis = normalVector->getAxis();
    Transformable::Point3f vectorAxis = _vector->getAxis();

    double diffuse = computeScalarProduct(normalAxis, vectorAxis);
    Transformable::Point3f reflect = {normalAxis.x * 2 * diffuse - vectorAxis.x, normalAxis.y * 2 * diffuse - vectorAxis.y, normalAxis.z * 2 * diffuse - vectorAxis.z};
    double specularScalarProduct = computeScalarProduct(reflect, _incident);
    if (specularScalarProduct < 0) {
        specularScalarProduct = 0;
    }
    int specular = (int)std::pow(specularScalarProduct, 25);
    Display::Color hittedColor = _vector->getHittedColor();
    Display::Color lightColor = _light->getColor();
    return Display::Color{hittedColor._r * (int)diffuse + lightColor._r * specular, hittedColor._g * (int)diffuse + lightColor._g * specular, hittedColor._b * (int)diffuse + lightColor._b * specular};
}

Display::Color Raytracer::LightCalculator::computePixel()
{
    _incident = _vector->getAxis();

    _vector->run(_light);
    HittedObject hittedObject = _vector->getHittedObject();

    //pour quand on handle plusieurs light check si le vector hit une des autre light que celle visée
    if (hittedObject == HittedObject::VOID) {
        return Display::Color{0, 0, 0};
    } else if (hittedObject == HittedObject::LIGHT) {
        return _light->getColor();
    }
    redirectVector();
    _vector->run(_light);
    hittedObject = _vector->getHittedObject();
    if (hittedObject == HittedObject::PRIMITIVE) {
        return Display::Color{0, 0, 0};
    } else if (hittedObject != HittedObject::LIGHT) {
        throw std::runtime_error("Error: LightCalculator::computePixel");
    }
    return compute();
}
