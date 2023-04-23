/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "ATransformable.hpp"

Transformable::ATransformable::ATransformable(Point3f pos, Point3f axis, TransformableType type) : _pos(pos), _axis(axis), _type(type)
{
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
