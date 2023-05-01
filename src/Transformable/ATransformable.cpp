/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "ATransformable.hpp"

Transformable::ATransformable::ATransformable(Point3d pos, Point3d axis) : _pos(pos), _axis(axis)
{
}

Transformable::Point3d Transformable::ATransformable::getPos()
{
    return _pos;
}

Transformable::Point3d Transformable::ATransformable::getAxis()
{
    return _axis;
}

void Transformable::ATransformable::setPos(Point3d pos)
{
    _pos = pos;
}

void Transformable::ATransformable::setAxis(Point3d axis)
{
    _axis = axis;
}
