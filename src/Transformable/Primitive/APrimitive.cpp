/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "APrimitive.hpp"

Transformable::Primitive::APrimitive::APrimitive(std::shared_ptr<Material::IMaterial> material, Point3f pos, Point3f axis)
    : ATransformable(pos, axis, TransformableType::PRIMITIVE), _material(material), _color(Display::Color{0, 0, 0}) {}

Display::Color Transformable::Primitive::APrimitive::getColor()
{
    return _color;
}

Transformable::Point3f Transformable::Primitive::APrimitive::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3f Transformable::Primitive::APrimitive::getAxis()
{
    return ATransformable::getAxis();
}

void Transformable::Primitive::APrimitive::setPos(Point3f pos)
{
    ATransformable::setPos(pos);
}

void Transformable::Primitive::APrimitive::setAxis(Point3f axis)
{
    ATransformable::setAxis(axis);
}

Transformable::TransformableType Transformable::Primitive::APrimitive::getType()
{
    return ATransformable::getType();
}
