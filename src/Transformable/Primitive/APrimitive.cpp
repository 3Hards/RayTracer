/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "APrimitive.hpp"

Transformable::Primitive::APrimitive::APrimitive(std::shared_ptr<Material::IMaterial> material, Point3d pos, Point3d axis)
    : ATransformable(pos, axis), _material(material) {}

Transformable::Point3d Transformable::Primitive::APrimitive::getSpecular()
{
    return _material->computeSpecular(_lastHittedVector);
}

Transformable::Point3d Transformable::Primitive::APrimitive::getMaterialBaseColor()
{
    return _material->getBaseColor();
}

Transformable::Point3d Transformable::Primitive::APrimitive::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3d Transformable::Primitive::APrimitive::getAxis()
{
    return ATransformable::getAxis();
}

void Transformable::Primitive::APrimitive::setPos(Point3d pos)
{
    ATransformable::setPos(pos);
}

void Transformable::Primitive::APrimitive::setAxis(Point3d axis)
{
    ATransformable::setAxis(axis);
}
