/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <cmath>
#include <iostream>


Transformable::Primitive::Sphere::Sphere(Point3f sphere, float ray, Material::IMaterial material) : Transformable::Primitive::APrimitive(material), _ray(ray), _position(sphere)
{
    std::cout << "Sphere created" << std::endl;
}

Transformable::Primitive::Sphere::~Sphere()
{
}

//foncction that check if the vector hit the sphere
std::tuple<bool, Display::Color> Transformable::Primitive::Sphere::checkHit(Raytracer::IVector &vector)
{
    Point3f vectorPos = vector.getPos();
    Point3f vectorAxis = vector.getAxis();
    Point3f spherePos = _position;
    float ray = _ray;
    float a = pow(vectorAxis.x, 2) + pow(vectorAxis.y, 2) + pow(vectorAxis.z, 2);
    float b = 2 * (vectorAxis.x * (vectorPos.x - spherePos.x) + vectorAxis.y * (vectorPos.y - spherePos.y) + vectorAxis.z * (vectorPos.z - spherePos.z));
    float c = pow(vectorPos.x - spherePos.x, 2) + pow(vectorPos.y - spherePos.y, 2) + pow(vectorPos.z - spherePos.z, 2) - pow(ray, 2);
    float delta = pow(b, 2) - 4 * a * c;
    if (delta < 0)
        return std::make_tuple(false, Display::Color{0, 0, 0});
    else
        return std::make_tuple(true, Display::Color{1, 1, 1});
}


