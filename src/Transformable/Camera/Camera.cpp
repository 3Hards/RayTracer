/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include <cmath>
#include "Camera.hpp"
#include "ATransformable.hpp"
#include "Vector.hpp"

namespace Transformable {
    namespace Camera {

        Camera::Camera(Point3d position, Point3d axis, unsigned int width,
            unsigned int height, double fov
        ) : ATransformable(position, axis), _width(width), _height(height)
        {
            double aspectRation = width / height;
            double theta = fov * M_PI / 180.0;
            double halfHeight = tan(theta / 2.0);
            double halfWidth = aspectRation * halfHeight;

            Point3d up{0, 1, 0};

            Point3d w = (_pos - _axis).normalized();
            Point3d u = up.cross(w).normalized();
            Point3d v = w.cross(u);

            _lower_left_corner = _pos - u * halfWidth - v * halfHeight - w;
            _horizontal = u * halfWidth * 2.0;
            _vertical = v * halfHeight * 2.0;
        }

        Point3d Camera::computeAxis(int x, int y)
        {
            return _lower_left_corner + _horizontal * x + _vertical * y - _pos;
        }

        unsigned int Camera::getWidth() const
        {
            return _width;
        }

        unsigned int Camera::getHeight() const
        {
            return _height;
        }

        Point3d Camera::getStartPixelPos() const
        {
            return _lower_left_corner;
        }

        Point3d Camera::getPos()
        {
            return ATransformable::getPos();
        }

        Point3d Camera::getAxis()
        {
            return ATransformable::getAxis();
        }

        void Camera::setPos(Point3d pos)
        {
            ATransformable::setPos(pos);
        }

        void Camera::setAxis(Point3d axis)
        {
            ATransformable::setAxis(axis);
        }
    }
}

