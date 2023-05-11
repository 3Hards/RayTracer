/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "ITransformable.hpp"

namespace Transformable {
    namespace Camera {

        /**
         * @brief Interface for the camera herit of ITransformable
        */
        class ICamera : public ITransformable {
            public:

                /**
                 * @brief Camera destructor
                */
                virtual ~ICamera() = default;

                /**
                 * @brief Get the Ray Axis
                 * @param x
                 * @param y
                 * @return Point3d Ray Axis
                */
                virtual Point3d getRayAxis(int x, int y) = 0;

                /**
                 * @brief Get the Width
                 * @return unsigned int Width
                */
                virtual unsigned int getWidth() const = 0;

                /**
                 * @brief Get the Height of camera
                 * @return unsigned int Height camera
                */
                virtual unsigned int getHeight() const = 0;

                /**
                 * @brief Set the Width camera
                 * @param width unsigned int
                 * @return void
                */
                virtual void setWidth(unsigned int width) = 0;

                /**
                 * @brief Set the Height camera
                 * @param height unsigned int
                 * @return void
                */
                virtual void setHeight(unsigned int height) = 0;

                /**
                 * @brief Move the camera forward
                 * @param distance double
                 * @return void
                */
                virtual void moveForward(double distance) = 0;

                /**
                 * @brief Move the camera right
                 * @param distance double
                 * @return void
                */
                virtual void moveRight(double distance) = 0;
                virtual void moveUp(double distance) = 0;

                /**
                 * @brief Rotate the camera on X axis
                 * @param angle double
                 * @return void
                */
                virtual void rotateX(double angle) = 0;

                /**
                 * @brief Rotate the camera on Y axis
                 * @param angle double
                 * @return void
                */
                virtual void rotateY(double angle) = 0;

                /**
                 * @brief Rotate the camera on Z axis
                 * @param angle double
                 * @return void
                */
                virtual void rotateZ(double angle) = 0;
        };
    }
}
