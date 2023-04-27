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
            Point3f position,
            Point3f axis,
            unsigned int width,
            unsigned int height,
            unsigned int fov
        ) : ATransformable(position, axis, TransformableType::Camera)
        {
            _fov = fov;
            _width = width;
            _height = height;
        }
        std::vector<Point3f> Camera::computeAxis() {
            std::vector<Point3f> axis;
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

        Point3f Camera::getPos() {
            return ATransformable::getPos();
        }

        Point3f Camera::getAxis() {
            return ATransformable::getAxis();
        }

        void Camera::setPos(Point3f pos) {
            ATransformable::setPos(pos);
        }

        void Camera::setAxis(Point3f axis) {
            ATransformable::setAxis(axis);
        }

        TransformableType Camera::getType() {
            return ATransformable::getType();
        }

    }
}
