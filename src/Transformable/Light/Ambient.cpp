/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight header
*/

#include "Ambient.hpp"
//see later
double ddot(Transformable::Point3d a, Transformable::Point3d b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

Transformable::Light::Ambient::Ambient(Display::Color color, float brightness, Point3d pos) : ALight(color, brightness, pos)
{}

bool Transformable::Light::Ambient::checkHit(std::unique_ptr<Raytracer::IVector> &vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    double a = ddot(vectorAxis, vectorAxis);
    Point3d dist = vectorPos - _pos;
    double b = 2.0 * ddot(vectorAxis, dist);
    double c = ddot(dist, dist) - 0.000001 * 0.000001;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) {
        return false;
    }
    double t1 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t2 = (-b + sqrt(discriminant)) / (2.0 * a);
    double t = std::min(t1, t2);
    if (t < 0) {
        return false;
    }
    Point3d hitPos = vectorPos + vectorAxis * t;
    vector->setPos(hitPos);
    return true;
}
