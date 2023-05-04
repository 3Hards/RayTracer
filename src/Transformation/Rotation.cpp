/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Translation
*/

#include "Rotation.hpp"

Transformation::Rotation::Rotation(Transformable::Point3d rotation): _rotation(rotation)
{
}

void Transformation::Rotation::cappedAdd(double &value, double change)
{
    value += change;
    if (value > 360) {
        value = value - 360;
    } else if (value < 0) {
        value = 361 + value;
    }
}

void Transformation::Rotation::applyTransformation(std::shared_ptr<Transformable::ITransformable> transformable)
{
    Transformable::Point3d axis = transformable->getAxis();
    cappedAdd(axis.x, _rotation.x);
    cappedAdd(axis.y, _rotation.y);
    cappedAdd(axis.z, _rotation.z);
    transformable->setAxis(axis);
}
