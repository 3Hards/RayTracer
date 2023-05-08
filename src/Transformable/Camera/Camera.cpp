/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include "ATransformable.hpp"
#include "Vector.hpp"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace Transformable {
    namespace Camera {

        Camera::Camera(
            Point3d position,
            Point3d axis,
            unsigned int width,
            unsigned int height,
            unsigned int fov
        ) : ATransformable(position, axis)
        {
            _fov = fov;
            _width = width;
            _height = height;
        }

        Transformable::Point3d Camera::getRayAxis(int x, int y)
        {
            Transformable::Point3d cameraDirection = {0, 0, 1};
            Transformable::Point3d cameraUp = {0, 1, 0};

            double fovScale = std::tan((_fov * M_PI / 180) / 2);
            double aspectRatio = _width / _height;
            double xx = (2 * ((double)x + 0.5) / _width - 1) * fovScale * aspectRatio;
            double yy = (1 - 2 * ((double)y + 0.5) / _height) * fovScale;
            Point3d rayDir = (cameraDirection + (cameraUp * yy) + cameraUp.cross(cameraDirection) * xx).normalize();
            return rayDir;
        }

        unsigned int Camera::getWidth() const {
            return _width;
        }

        unsigned int Camera::getHeight() const {
            return _height;
        }

        Point3d Camera::getPos() {
            return ATransformable::getPos();
        }

        Point3d Camera::getAxis() {
            return ATransformable::getAxis();
        }

        void Camera::setPos(Point3d pos) {
            ATransformable::setPos(pos);
        }

        void Camera::setAxis(Point3d axis) {
            ATransformable::setAxis(axis);
        }
    }
}
