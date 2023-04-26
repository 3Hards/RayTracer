/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight
*/

#include "ALight.hpp"

Transformable::Light::ALight::ALight(Display::Color color, float brightness, Point3f pos) : ATransformable(pos, Point3f{0, 0, 0}, TransformableType::LIGHT), _color(color), _brightness(brightness)
{
    if (_brightness > 1) {
        _brightness = 1;
    } else if (_brightness < 0) {
        _brightness = 0;
    }
}

float Transformable::Light::ALight::getBrightness()
{
    return _brightness;
}

Transformable::Point3f Transformable::Light::ALight::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3f Transformable::Light::ALight::getAxis()
{
    return ATransformable::getAxis();
}

void Transformable::Light::ALight::setPos(Point3f pos)
{
    ATransformable::setPos(pos);
}

void Transformable::Light::ALight::setAxis(Point3f axis)
{
    ATransformable::setAxis(axis);
}

Transformable::TransformableType Transformable::Light::ALight::getType()
{
    return ATransformable::getType();
}
