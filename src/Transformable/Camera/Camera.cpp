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
#include "Matrix3D.hpp"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace Transformable
{
    namespace Camera
    {

        Camera::Camera(
            Point3d position,
            Point3d axis,
            unsigned int width,
            unsigned int height,
            unsigned int fov) :
        ATransformable(position, axis),
        _fov(fov),
        _width(width),
        _height(height),
        _cameraDirection({1, 0, 0}),
        _cameraUp({0, 0, 1})
        {
            _aspectRatio = (double)width / (double)height;
            _fovScale = std::tan((_fov * M_PI / 180) / 2);
        }

        void Camera::render()
        {
            _vector->setPos(_pos);

            for (unsigned int y = 0; y < _height; y++) {
                for (unsigned int x = 0; x < _width; x++) {
                    _vector->setAxis(getRayAxis(x, y));
                    _displayer->addPixelToImage(Display::Pixel{_vector->computeColor(), Display::Point2i{(int)x, (int)y}});
                }
            }
        }

        Transformable::Point3d Camera::getRayAxis(int x, int y)
        {
            double angleXRad = getAxis().x * M_PI / 180;
            double angleYRad = getAxis().y * M_PI / 180;
            double angleZRad = getAxis().z * M_PI / 180;

            double xNormalized = (2 * ((x + 0.5) / _width) - 1) * _fovScale * _aspectRatio * -1;
            double yNormalized = (1 - 2 * ((y + 0.5) / _height)) * _fovScale;

            Transformable::Matrix3d rotationMatrix = Transformable::Matrix3d().rotateY(angleYRad).rotateX(angleXRad).rotateZ(angleZRad);
            Transformable::Point3d cameraDirectionRotated = rotationMatrix * _cameraDirection;
            Transformable::Point3d cameraUpRotated = rotationMatrix * _cameraUp;
            Transformable::Point3d cameraRight = cameraDirectionRotated.cross(cameraUpRotated);
            Transformable::Point3d rayDirection = cameraDirectionRotated + cameraRight * xNormalized + cameraUpRotated * yNormalized;

            return rayDirection;
        }

        void Camera::moveForward(double distance) {
            Point3d forwardVector = {1, 0, 0};

            Matrix3d rotationMatrixX = Matrix3d().rotateX(_axis.x * M_PI / 180);
            Matrix3d rotationMatrixY = Matrix3d().rotateY(_axis.y * M_PI / 180);
            Matrix3d rotationMatrixZ = Matrix3d().rotateZ(_axis.z * M_PI / 180);

            forwardVector = rotationMatrixX * forwardVector;
            forwardVector = rotationMatrixY * forwardVector;
            forwardVector = rotationMatrixZ * forwardVector;
            forwardVector = forwardVector * distance;
            
            setPos(getPos() + forwardVector);
        }

        void Camera::moveRight(double distance) {
            Point3d rightVector = {0, 1, 0};

            Matrix3d rotationMatrixX = Matrix3d().rotateX(_axis.x * M_PI / 180);
            Matrix3d rotationMatrixY = Matrix3d().rotateY(_axis.y * M_PI / 180);
            Matrix3d rotationMatrixZ = Matrix3d().rotateZ(_axis.z * M_PI / 180);
            
            rightVector = rotationMatrixX * rightVector;
            rightVector = rotationMatrixY * rightVector;
            rightVector = rotationMatrixZ * rightVector;
            rightVector = rightVector * distance;
            
            setPos(getPos() + rightVector);
        }

        void Camera::moveUp(double distance) {
            Point3d resultVector = {0, 0, 1};

            Matrix3d rotationMatrixX = Matrix3d().rotateX(_axis.x * M_PI / 180);
            Matrix3d rotationMatrixY = Matrix3d().rotateY(_axis.y * M_PI / 180);
            Matrix3d rotationMatrixZ = Matrix3d().rotateZ(_axis.z * M_PI / 180);

            resultVector = rotationMatrixX * resultVector;
            resultVector = rotationMatrixY * resultVector;
            resultVector = rotationMatrixZ * resultVector;
            
            resultVector = resultVector * distance;

            setPos(getPos() + resultVector);
        }

        void Camera::rotateX(double angle) {
            _axis.x += angle;
            if (_axis.x > 360)
                _axis.x = 0;
            if (_axis.x < 0)
                _axis.x = 360;
        }

        void Camera::rotateZ(double angle) {
            _axis.z += angle;
            if (_axis.z > 360)
                _axis.z = 0;
            if (_axis.z < 0)
                _axis.z = 360;
        }

        void Camera::rotateY(double angle) {
            _axis.y += angle;
            if (_axis.y > 360)
                _axis.y = 0;
            if (_axis.y < 0)
                _axis.y = 360;
        }

        void Camera::render(std::shared_ptr<Raytracer::IVector> vector, std::string fileName)
        {
            _vector = vector;
            _displayer = std::make_shared<Display::LibGraphicHandler>(fileName, _width, _height);
            render();
            _displayer->exportImage();
        }

        void Camera::render(std::shared_ptr<Raytracer::IVector> vector)
        {
            _vector = vector;
            // modif LibGraphicHandler to be constructed without fileName, meaning we want window rendering
            //_displayer->drawImage() (or something else)
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
