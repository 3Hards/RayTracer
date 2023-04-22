/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#pragma once

#include <vector>
#include "ICamera.hpp"
#include "../ATransformable.hpp"

namespace Transformable {
    namespace Camera {
        /**
         * @brief This class is used to create a camera
         * @param fov Field of view
         * @param width Number of pixels on the width
         * @param height Number of pixels on the height
         * @param position Position of the camera (x, y, z)
         * @param axis Axis of the camera (in degrees)
         * @return Camera
         * @example Camera camera(90, 1920, 1080, {1, 2, 3}, {55, 90, 50});
         * 
         */
        class Camera : public ICamera, public ATransformable {
            public:
                Camera(
                    int fov = 90,
                    int width = 1920,
                    int height = 1080,
                    Point3f position = {0, 0, 0},
                    Point3f axis = {0, 0, 0}
                );
                std::vector<Raytracer::IVector> getVectors();
            private:
                int _fov;
                int _width;
                int _height;
                std::vector<Raytracer::IVector> _vectors;
        };
    }
}
