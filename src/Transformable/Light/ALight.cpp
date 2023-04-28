/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ALight
*/

#include "ALight.hpp"

Transformable::Light::ALight::ALight(Display::Color color, float brightness, Point3d pos) : ATransformable(pos, Point3d{0, 0, 0}), _brightness(brightness)
{
    if (_brightness > 1) {
        _brightness = 1;
    } else if (_brightness < 0) {
        _brightness = 0;
    }
    _color.x = color._r / 255;
    _color.y = color._g / 255;
    _color.z = color._b / 255;
    _ambientColor.x = _color.x * _brightness;
    _ambientColor.y = _color.y * _brightness;
    _ambientColor.z = _color.z * _brightness;
}

Transformable::Point3d Transformable::Light::ALight::getAmbientLightColor()
{
    return _ambientColor;
}

Transformable::Point3d Transformable::Light::ALight::getLightColor()
{
    return _color;
}

Transformable::Point3d Transformable::Light::ALight::getPos()
{
    return ATransformable::getPos();
}

Transformable::Point3d Transformable::Light::ALight::getAxis()
{
    return ATransformable::getAxis();
}

void Transformable::Light::ALight::setPos(Point3d pos)
{
    ATransformable::setPos(pos);
}

void Transformable::Light::ALight::setAxis(Point3d axis)
{
    ATransformable::setAxis(axis);
}
