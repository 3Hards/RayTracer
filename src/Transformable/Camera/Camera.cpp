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
            int fov,
            int width,
            int height,
            Point3f position,
            Point3f axis
        ) : ATransformable(position, axis, TransformableType::Camera)
        {
            _fov = fov;
            _width = width;
            _height = height;
            computeVectors();
        }

        std::vector<std::shared_ptr<Raytracer::IVector>> Camera::getVectors() const {
            return _vectors;
        }

        void Camera::computeVectors() {
            Point3f pos = {0, 0, 0};
            Point3f axis = {0, 0, 0};

            //for the V1 of the camera, we create a rectangle of vectors
            //the origin is le top left corner of the rectangle

            for (int y = 0; y < _height; y++) {
                for (int x = 0; x < _width; x++) {
                    pos.x = _pos.x + x;
                    pos.y = _pos.y + y;
                    pos.z = _pos.z;
                    axis.x = _axis.x;
                    axis.y = _axis.y;
                    axis.z = _axis.z;
                    Raytracer::Vector vector = Raytracer::Vector(pos, axis, Transformable::TransformableType::Vector);
                    _vectors.push_back(std::make_shared<Raytracer::Vector>(vector));
                }
            }
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
