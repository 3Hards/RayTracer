/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** Sphere
*/

#include "Sphere.hpp"
#include <cmath>
#include <iostream>


Transformable::Primitive::Sphere::Sphere(Point3f pos, float _ray, Material::IMaterial material) : Transformable::Primitive::APrimitive(material, pos, {0, 0, 0}), _ray(_ray)
{
}

//function that check if the vector hit the sphere
std::tuple<bool, Display::Color> Transformable::Primitive::Sphere::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3f vectorPos = vector->getPos();
    Point3f vectorAxis = vector->getAxis();
    float a = pow(vectorAxis.x, 2) + pow(vectorAxis.y, 2) + pow(vectorAxis.z, 2);
    float b = 2 * (vectorAxis.x * (vectorPos.x - _pos.x) + vectorAxis.y * (vectorPos.y - _pos.y) + vectorAxis.z * (vectorPos.z - _pos.z));
    float c = pow(vectorPos.x - _pos.x, 2) + pow(vectorPos.y - _pos.y, 2) + pow(vectorPos.z - _pos.z, 2) - pow(_ray, 2);
    float delta = pow(b, 2) - 4 * a * c;

    if (delta >= 0) {
        float t1 = (-b - sqrt(delta)) / (2 * a);
        float t2 = (-b + sqrt(delta)) / (2 * a);

        Point3f intersection1 = { vectorPos.x + t1 * vectorAxis.x,
                                vectorPos.y + t1 * vectorAxis.y,
                                vectorPos.z + t1 * vectorAxis.z };
        Point3f intersection2 = { vectorPos.x + t2 * vectorAxis.x,
                                vectorPos.y + t2 * vectorAxis.y,
                                vectorPos.z + t2 * vectorAxis.z };

        float distance1 = sqrt(pow(intersection1.x - _pos.x, 2) +
                            pow(intersection1.y - _pos.y, 2) +
                            pow(intersection1.z - _pos.z, 2));
        float distance2 = sqrt(pow(intersection2.x - _pos.x, 2) +
                            pow(intersection2.y - _pos.y, 2) +
                            pow(intersection2.z - _pos.z, 2));

        if (distance1 <= _ray || distance2 <= _ray) {
            return std::make_tuple(true, Display::Color{1, 1, 1});
        }
    }
    return std::make_tuple(false, Display::Color{0, 0, 0});
}
