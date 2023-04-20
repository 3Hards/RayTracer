/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#include <math.h>
#include <array>
#include "Vector.hpp"

Raytracer::Vector::Vector() {}

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>> primitives)
{
    _primitives = primitives;
}

void Raytracer::Vector::moveForward()
{
    std::array<std::array<double, 3>, 3> rot_x = {{{1, 0, 0}, {0, cos(_axis.x), -sin(_axis.x)}, {0, sin(_axis.x), cos(_axis.x)}}};
    std::array<std::array<double, 3>, 3> rot_y = {{{cos(_axis.y), 0, sin(_axis.y)}, {0, 1, 0}, {-sin(_axis.y), 0, cos(_axis.y)}}};
    std::array<std::array<double, 3>, 3> rot_z = {{{cos(_axis.z), -sin(_axis.z), 0}, {sin(_axis.z), cos(_axis.z), 0}, {0, 0, 1}}};
    std::array<std::array<double, 3>, 3> rot_matrix;
    double distance = 1.0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            rot_matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                rot_matrix[i][j] += rot_z[i][k] * rot_y[k][j] * rot_x[k][j];
            }
        }
    }

    std::array<double, 3> direction = {rot_matrix[0][2], rot_matrix[1][2], rot_matrix[2][2]};
    std::array<double, 3> translation = {direction[0] * distance, direction[1] * distance, direction[2] * distance};

    _pos.x += translation[0];
    _pos.y += translation[1];
    _pos.z += translation[2];
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
