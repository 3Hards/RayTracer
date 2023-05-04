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
                    double fov = 90
                );
                Point3d getPos() final;
                Point3d getAxis() final;
                void setPos(Point3d pos) final;
                void setAxis(Point3d axis) final;
                Point3d computeAxis(int x, int y) final;
                unsigned int getWidth() const final;
                unsigned int getHeight() const final;
                Point3d getOrigin() const final;

            private:
                unsigned int _width;
                unsigned int _height;
                double _camFov;
                double f;
                double m11, m12, m13;
                double m21, m22, m23;
                double m31, m32, m33;
                double m41, m42, m43;
                //Point3d _m1;
                //Point3d _m2;
                //Point3d _m3;
                //Point3d _m4;
        };
    }
}
