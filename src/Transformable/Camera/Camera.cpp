/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Camera
*/

#include <iostream>
#include "Camera.hpp"
#include "LibGraphicHandler.hpp"
#include "ATransformable.hpp"
#include "Vector.hpp"

namespace Transformable
{
    namespace Camera
    {

        Camera::Camera(
            Point3d position,
            Point3d axis,
            unsigned int width,
            unsigned int height,
            unsigned int fov) : ATransformable(position, axis)
        {
            _fov = fov;
            _width = width;
            _height = height;
        }

        void Camera::render()
        {
            _vector->setAxis(_axis);

            for (unsigned int y = 0; y < _height; y++) {
                for (unsigned int x = 0; x < _width; x++) {
                    Transformable::Point3d pos{_pos.x + x, _pos.y + y, _pos.z};
                    _vector->setPos(pos);
                    Display::Color res = _vector->computeColor();
                    _displayer->addPixelToImage(Display::Pixel{res, Display::Point2i{(int)x, (int)y}});
                    std::cout << "addPixel " << pos.x << " " << pos.y << " " << res._r << " " << res._g << " " << res._b << _vector->getAxis().x << " " << _vector->getAxis().y << " " << _vector->getAxis().z << std::endl;
                }
            }
            _displayer->exportImage();
        }

        void Camera::render(std::shared_ptr<Raytracer::IVector> vector, std::string fileName)
        {
            _vector = vector;
            _displayer = std::make_shared<Display::LibGraphicHandler>(fileName, _width, _height);
            render();
        }

        void Camera::render(std::shared_ptr<Raytracer::IVector> vector)
        {
            _vector = vector;
            // modif LibGraphicHandler to be constructed without fileName, meaning we want window rendering
        }

        Point3d Camera::getPos()
        {
            return ATransformable::getPos();
        }

        Point3d Camera::getAxis()
        {
            return ATransformable::getAxis();
        }

        void Camera::setPos(Point3d pos)
        {
            ATransformable::setPos(pos);
        }

        void Camera::setAxis(Point3d axis)
        {
            ATransformable::setAxis(axis);
        }
    }
}
