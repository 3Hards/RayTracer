/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#pragma once

#include <vector>
#include <memory>
#include "ICamera.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Camera {
        /**
         * @brief This class is used to create a camera
         * @param position Position of the camera (x, y, z)
         * @param axis Axis of the camera (in degrees)
         * @param width Number of pixels on the width
         * @param height Number of pixels on the height
         * @param fov Field of view
         * @return Camera
         * @example Camera camera(90, 1920, 1080, {1, 2, 3}, {55, 90, 50});
         *
         */
        class Camera : public ICamera, public ATransformable {
            public:
                Camera(
                    Point3f position = {0, 0, 0},
                    Point3f axis = {0, 0, 0},
                    int width = 1920,
                    int height = 1080,
                    int fov = 90
                );
                std::vector<std::shared_ptr<Raytracer::IVector>> computeVectors() final;
                Point3f getPos() final;
                Point3f getAxis() final;
                void setPos(Point3f pos) final;
                void setAxis(Point3f axis) final;
                TransformableType getType() final;

            private:
                int _fov;
                int _width;
                int _height;
        };
    }
}
