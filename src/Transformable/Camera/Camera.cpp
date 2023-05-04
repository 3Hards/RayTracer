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
            double _f = (height / 2.0) / tan(fov / 2.0);

            Point3d c = {std::cos(_axis.x), std::cos(_axis.y), std::cos(_axis.z)};
            Point3d s = {std::sin(_axis.x), std::sin(_axis.y), std::sin(_axis.z)};

            Point3d t = {-_pos.x, -_pos.y, -_pos.z};

            _m1 = {c.y * c.z, c.y * s.z, 0.0};
            _m2 = {s.x * s.y * c.z - c.x * s.z, s.x * s.y * s.z + c.x * c.z, s.x * c.y};
            _m3 = {c.x * s.y * c.z + s.x * s.z, c.x * s.y * s.z - s.x * c.z, c.x * c.y};
            _m4 = {t.x * _m1.x + t.y * _m2.x + t.z * _m3.x,
                t.x * _m1.y + t.y * _m2.y + t.z * _m3.y,
                t.x * _m1.z + t.y * _m2.z + t.z * _m3.z};
        }

        Point3d Camera::computeAxis(int x, int y)
        {
            Point3d n = {(x - _height/2.0) / _f,
                (y - _height/2.0) / _f, 1.0};

            Point3d w = {n.x * _m1.x + n.y * _m2.x + n.z * _m3.x + _m4.x,
                n.x * _m1.y + n.y * _m2.y + n.z * _m3.y + _m4.y,
                n.x * _m1.z + n.y * _m2.z + n.z * _m3.z + _m4.z};

            Point3d d = {w.x - _pos.x, w.y - _pos.y, w.z - _pos.z};
            return d.normalized();
        }

        unsigned int Camera::getWidth() const
        {
            return _width;
        }

        unsigned int Camera::getHeight() const
        {
            return _height;
        }

        Point3d Camera::getOrigin() const
        {
            return _pos;
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

