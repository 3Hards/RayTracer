/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#include "Vector.hpp"

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>> primitives)
{
    _primitives = primitives;
}

void Raytracer::Vector::moveForward()
{

}

std::tuple<bool, Display::Color> Raytracer::Vector::checkHit()
{
    std::tuple<bool, Display::Color> res;

    for (auto primitive : _primitives) {
        res = primitive->checkHit(*this);
        if (std::get<0>(res) == true) {
            return res;
        }
    }
    return std::make_tuple(false, Display::Color{0, 0, 0});
}

std::tuple<bool, Display::Color, Transformable::Point3f> Raytracer::Vector::run(Transformable::ILight)
{
    std::tuple<bool, Display::Color> res;

    for (int i = 0; i < 100; i++) {
        res = checkHit();
        if (std::get<0>(res) == true) {
            return std::make_tuple(std::get<0>(res), std::get<1>(res), _pos);
        }
        moveForward();
    }
    return std::make_tuple(false, Display::Color{0, 0, 0}, Transformable::Point3f{0, 0, 0});
}
