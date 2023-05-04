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
            double camres_y = 1080;
            _camFov = fov;
            Transformable::Point3d camPos = {-110, 0, 110};
            Transformable::Point3d camDirection = {0, -20, 0};

            f = (camres_y / 2.0) / tan(_camFov / 2.0);

            double cx = cos(camDirection.x), cy = cos(camDirection.y), cz = cos(camDirection.z);
            double sx = sin(camDirection.x), sy = sin(camDirection.y), sz = sin(camDirection.z);

            double tx = -camPos.x, ty = -camPos.y, tz = -camPos.z;

            m11 = cy * cz, m12 = cy * sz, m13 = 0.0;
            m21 = sx * sy * cz - cx * sz, m22 = sx * sy * sz + cx * cz, m23 = sx * cy;
            m31 = cx * sy * cz + sx * sz, m32 = cx * sy * sz - sx * cz, m33 = cx * cy;
            m41 = tx * m11 + ty * m21 + tz * m31;
            m42 = tx * m12 + ty * m22 + tz * m32;
            m43 = tx * m13 + ty * m23 + tz * m33;
            //_f = (height / 2.0) / tan(fov / 2.0);
//
            //Point3d c = {std::cos(_axis.x), std::cos(_axis.y), std::cos(_axis.z)};
            //Point3d s = {std::sin(_axis.x), std::sin(_axis.y), std::sin(_axis.z)};
//
            //Point3d t = {-_pos.x, -_pos.y, -_pos.z};
//
            //_m1 = {c.y * c.z, c.y * s.z, 0.0};
            //_m2 = {s.x * s.y * c.z - c.x * s.z, s.x * s.y * s.z + c.x * c.z, s.x * c.y};
            //_m3 = {c.x * s.y * c.z + s.x * s.z, c.x * s.y * s.z - s.x * c.z, c.x * c.y};
            //_m4 = _m1 * t.x + _m2 * t.y + _m3 * t.z;
        }

        Point3d Camera::computeAxis(int x, int y)
        {
            double nx = (x - _height/2.0) / f;
            double ny = (y - _height/2.0) / f;
            double nz = 1.0;

            double wx = nx * m11 + ny * m21 + nz * m31 + m41;
            double wy = nx * m12 + ny * m22 + nz * m32 + m42;
            double wz = nx * m13 + ny * m23 + nz * m33 + m43;

            double dx = wx - _pos.x;
            double dy = wy - _pos.y;
            double dz = wz - _pos.z;
            double norm = sqrt(dx*dx + dy*dy + dz*dz);

            Transformable::Point3d direction = {0, 0, 0};
            direction.x = dx / norm;
            direction.y = dy / norm;
            direction.z = dz / norm;
            return direction;
            //Point3d n = {(x - _height/2.0) / _f,
            //    (y - _height/2.0) / _f, 1.0};
//
            //Point3d w = _m1 * n.x + _m2 * n.y + _m3 * n.z + _m4;
//
            //return (w - _pos).normalized();
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

