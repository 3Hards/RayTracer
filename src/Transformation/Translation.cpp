/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Translation
*/

#include "Translation.hpp"

Transformation::Translation::Translation(Transformable::Point3d translation) : _translation(translation)
{
}

void Transformation::Translation::applyTransformation(std::shared_ptr<Transformable::ITransformable> transformable)
{
    Transformable::Point3d pos = transformable->getPos();

    pos.x += _translation.x;
    pos.y += _translation.y;
    pos.z += _translation.z;
    transformable->setPos(pos);
}
