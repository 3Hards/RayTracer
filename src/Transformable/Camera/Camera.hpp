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
#include "ILibGraphicHandler.hpp"
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
                void render(std::shared_ptr<Raytracer::IVector> vector, std::string fileName) final;
                void render(std::shared_ptr<Raytracer::IVector> vector) final;
                Point3d getPos() final;
                Point3d getAxis() final;
                void setPos(Point3d pos) final;
                void setAxis(Point3d axis) final;

            private:
                void render();
                std::shared_ptr<Raytracer::IVector> _vector;
                std::shared_ptr<Display::ILibGraphicHandler> _displayer;
                unsigned int _fov;
                unsigned int _width;
                unsigned int _height;
        };
    }
}
