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
        }
    }
}
