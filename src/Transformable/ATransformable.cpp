/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "ATransformable.hpp"

Transformable::ATransformable::ATransformable()
{
    _pos = {0, 0, 0};
    _axis = {0, 0, 0};
}

Transformable::Point3f Transformable::ATransformable::getPos()
{
    return _pos;
}

Transformable::Point3f Transformable::ATransformable::getAxis()
{
    return _axis;
}

void Transformable::ATransformable::setPos(Point3f pos)
{
    _pos = pos;
}

void Transformable::ATransformable::setAxis(Point3f axis)
{
    _axis = axis;
}

Transformable::TransformableType Transformable::ATransformable::getType()
{
    return _type;
}
