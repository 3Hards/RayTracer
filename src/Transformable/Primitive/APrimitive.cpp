/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "APrimitive.hpp"

Transformable::Primitive::APrimitive::APrimitive(std::shared_ptr<Material::IMaterial> material, Point3f pos, Point3f axis)
    : ATransformable(pos, axis, TransformableType::Primitive), _material(material) {}

Transformable::Point3f Transformable::Primitive::APrimitive::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3f Transformable::Primitive::APrimitive::getAxis()
{
    return ATransformable::getAxis();
}

void Transformable::Primitive::APrimitive::setPos(Transformable::Point3f pos)
{
    ATransformable::setPos(pos);
}

void Transformable::Primitive::APrimitive::setAxis(Transformable::Point3f axis)
{
    ATransformable::setAxis(axis);
}

Transformable::TransformableType Transformable::Primitive::APrimitive::getType()
{
    return ATransformable::getType();
}
