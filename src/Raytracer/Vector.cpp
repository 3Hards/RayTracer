/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector
*/

#ifdef _WIN32
    #define _USE_MATH_DEFINES
#endif
#include <cmath>
#include <array>
#include "Vector.hpp"
#include "ILight.hpp"

Raytracer::Vector::Vector(Transformable::Point3f pos, Transformable::Point3f axis) : ATransformable(pos, axis, Transformable::TransformableType::Vector)
{}

void Raytracer::Vector::setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> primitives)
{
    _primitives = primitives;
}

double Raytracer::Vector::toRad(double degree)
{
    return degree * (M_PI / 180);
}

void Raytracer::Vector::moveForward()
{
    std::array<std::array<double, 3>, 3> rot_x = {{{1, 0, 0}, {0, cos(toRad(_axis.x)), -sin(toRad(_axis.x))}, {0, sin(toRad(_axis.x)), cos(toRad(_axis.x))}}};
    std::array<std::array<double, 3>, 3> rot_y = {{{cos(toRad(_axis.y)), 0, sin(toRad(_axis.y))}, {0, 1, 0}, {-sin(toRad(_axis.y)), 0, cos(toRad(_axis.y))}}};
    std::array<std::array<double, 3>, 3> rot_z = {{{cos(toRad(_axis.z)), -sin(toRad(_axis.z)), 0}, {sin(toRad(_axis.z)), cos(toRad(_axis.z)), 0}, {0, 0, 1}}};
    std::array<std::array<double, 3>, 3> rot_matrix;
    double distance = 1;

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
    std::unique_ptr<Raytracer::IVector> vector = std::make_unique<Raytracer::Vector>(*this);

    for (auto primitive : _primitives) {
        res = primitive->checkHit(vector);
        if (std::get<0>(res) == true) {
            return res;
        }
    }
    return std::make_tuple(false, Display::Color{0, 0, 0});
}

bool Raytracer::Vector::checkDistances(std::vector<double> &prevDistances)
{
    std::vector<double> newDistances = getDistances();

    for (std::size_t i = 0; i < prevDistances.size(); i++) {
        if (prevDistances[i] > newDistances[i]) {
            prevDistances = newDistances;
            return false;
        }
    }
    return true;
}

std::vector<double> Raytracer::Vector::getDistances()
{
    std::vector <double> _distances;

    for (auto primitive : _primitives) {
        Transformable::Point3f pos = primitive->getPos();
        _distances.push_back(pow(pow(pos.x - _pos.x, 2) + pow(pos.y - _pos.y, 2) + pow(pos.z - _pos.z, 2), 0.5));

    }
    return _distances;
}

std::tuple<bool, Display::Color, Transformable::Point3f> Raytracer::Vector::run(std::shared_ptr<Transformable::Light::ILight>)
{
    std::tuple<bool, Display::Color> res;
    std::vector<double> prevDistances = getDistances();
    bool moveInVoid = false;

    while (moveInVoid == false) {
        res = checkHit();
        if (std::get<0>(res) == true) {
            return std::make_tuple(std::get<0>(res), std::get<1>(res), _pos);
        }
        moveForward();
        moveInVoid = checkDistances(prevDistances);
    }
    return std::make_tuple(false, Display::Color{0, 0, 0}, Transformable::Point3f{0, 0, 0});
}

Transformable::Point3f Raytracer::Vector::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3f Raytracer::Vector::getAxis()
{
    return ATransformable::getAxis();
}

void Raytracer::Vector::setPos(Transformable::Point3f pos)
{
    ATransformable::setPos(pos);
}

void Raytracer::Vector::setAxis(Transformable::Point3f axis)
{
    ATransformable::setAxis(axis);
}

Transformable::TransformableType Raytracer::Vector::getType()
{
    return ATransformable::getType();
}
