/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include "ATransformable.hpp"
#include "Vector.hpp"

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
        std::vector<Point3d> Camera::computeAxis() {
            std::vector<Point3d> axis;
            //for the V1 of the camera, we create a rectangle
            //the vectors do not start from the same origin, they go straight to the camera

            for (unsigned int y = 0; y < _height; y++) {
                for (unsigned int x = 0; x < _width; x++) {
                    axis.push_back(_axis);
                }
            }
            return axis;
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
