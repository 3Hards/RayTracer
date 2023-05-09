/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ICamera
*/

#pragma once

#include <vector>
#include "IVector.hpp"
#include "ITransformable.hpp"

namespace Transformable {
    namespace Camera {
        class ICamera : public ITransformable {
            public:
                virtual ~ICamera() = default;
                virtual void render(std::shared_ptr<Raytracer::IVector> vector, std::string fileName) = 0;
                virtual void render(std::shared_ptr<Raytracer::IVector> vector) = 0;
                virtual void moveForward(double distance) = 0;
                virtual void moveRight(double distance) = 0;
                virtual void moveUp(double distance) = 0;
                virtual void rotateX(double angle) = 0;
                virtual void rotateY(double angle) = 0;
                virtual void rotateZ(double angle) = 0;
            private:
                virtual Point3d getRayAxis(int x, int y) = 0;
        };
    }
}
