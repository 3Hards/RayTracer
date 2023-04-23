/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "APrimitive.hpp"

Transformable::Primitive::APrimitive::APrimitive(Material::IMaterial material, Point3f pos, Point3f axis)
    : ATransformable(pos, axis, TransformableType::Primitive), _material(material) {}
