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
                    Point3d position = {0, 0, 0},
                    Point3d axis = {0, 0, 0},
                    unsigned int width = 1920,
                    unsigned int height = 1080,
                    unsigned int fov = 90
                );
                Point3d getPos() final;
                Point3d getAxis() final;
                void setPos(Point3d pos) final;
                void setAxis(Point3d axis) final;
                Point3d Camera::getRayAxis(int x, int y);
                unsigned int getWidth() const final;
                unsigned int getHeight() const final;
                void moveForward(double distance);
                void moveRight(double distance);
                void moveUp(double distance);
                void rotateX(double angle);
                void rotateY(double angle);
                void rotateZ(double angle);

            private:
                unsigned int _fov;
                unsigned int _width;
                unsigned int _height;
                double _aspectRatio;
                double _fovScale;
                Point3d _cameraDirection;
                Point3d _cameraUp;
        };
    }
}
