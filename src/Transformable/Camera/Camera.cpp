/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include "Camera.hpp"
#include "../ATransformable.hpp"

namespace Transformable {
    namespace Camera {

        Camera::Camera(
            int fov,
            int width,
            int height,
            Point3f position,
            Point3f axis
        ) : ATransformable()
        {
            _fov = fov;
            _width = width;
            _height = height;
            _pos = position;
            _axis = axis;
            _type = TransformableType::Camera;
            computeVectors();
        }

        std::vector<std::shared_ptr<Raytracer::IVector>> Camera::getVectors() const {
            return _vectors;
        }

        void Camera::computeVectors() {
            //TODO: Compute vectors
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
