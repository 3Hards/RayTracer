/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include "ITransformable.hpp"
#include "LightCalculator.hpp"
#include "LibGraphicHandler.hpp"
#include "IVector.hpp"
#include "Vector.hpp"
#include "cmath"

#include <iostream>

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace Transformable {

    class Matrix3d {
    private:
        double data[3][3];

    public:
        Matrix3d() {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    data[i][j] = (i == j) ? 1.0 : 0.0;
                }
            }
        }

        Matrix3d rotateX(double angle) {
            Matrix3d rotationMatrix;
            rotationMatrix.data[1][1] = std::cos(angle);
            rotationMatrix.data[1][2] = -std::sin(angle);
            rotationMatrix.data[2][1] = std::sin(angle);
            rotationMatrix.data[2][2] = std::cos(angle);
            return (*this) * rotationMatrix;
        }

        Matrix3d rotateY(double angle) {
            Matrix3d rotationMatrix;
            rotationMatrix.data[0][0] = std::cos(angle);
            rotationMatrix.data[0][2] = std::sin(angle);
            rotationMatrix.data[2][0] = -std::sin(angle);
            rotationMatrix.data[2][2] = std::cos(angle);
            return (*this) * rotationMatrix;
        }

        Matrix3d rotateZ(double angle) {
            Matrix3d rotationMatrix;
            rotationMatrix.data[0][0] = std::cos(angle);
            rotationMatrix.data[0][1] = -std::sin(angle);
            rotationMatrix.data[1][0] = std::sin(angle);
            rotationMatrix.data[1][1] = std::cos(angle);
            return (*this) * rotationMatrix;
        }

        Matrix3d operator*(const Matrix3d& other) const {
            Matrix3d result;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    result.data[i][j] = 0.0;
                    for (int k = 0; k < 3; k++) {
                        result.data[i][j] += data[i][k] * other.data[k][j];
                    }
                }
            }
            return result;
        }

        double& operator()(int i, int j) {
            return data[i][j];
        }

        const double& operator()(int i, int j) const {
            return data[i][j];
        }
    };

    Point3d operator*(const Matrix3d& matrix, const Point3d& point) {
        Point3d result;
        result.x = matrix(0, 0) * point.x + matrix(0, 1) * point.y + matrix(0, 2) * point.z;
        result.y = matrix(1, 0) * point.x + matrix(1, 1) * point.y + matrix(1, 2) * point.z;
        result.z = matrix(2, 0) * point.x + matrix(2, 1) * point.y + matrix(2, 2) * point.z;
        return result;
    }
}

namespace Scene {

    void Scene::addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera)
    {
        _cameras.push_back(camera);
    }

    void Scene::addLight(std::shared_ptr<Transformable::Light::ILight> light)
    {
        _lights.push_back(light);
    }

    void Scene::addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive)
    {
        _primitives.push_back(primitive);
    }

    void Scene::addTransformation(std::shared_ptr<Transformation::ITransformation> transformation)
    {
        _transformations.push_back(transformation);
    }

    Transformable::Point3d getRayDirection(int x, int y, std::shared_ptr<Transformable::Camera::ICamera> camera)
    {
        // camres = 1920 1080
        // camFov = 90
        // camPos = 0 0 0
        // camDirection = 0 0 1
        // camUp = 0 1 0

        double angleXRad = camera->getAxis().x * M_PI / 180;
        double angleYRad = camera->getAxis().y * M_PI / 180;
        double angleZRad = camera->getAxis().z * M_PI / 180;

        double fovScale = std::tan((90 * M_PI / 180) / 2);
        double aspectRatio = 600.0 / 400.0;
        
        double xx = (2 * ((x + 0.5) / 600) - 1) * fovScale * aspectRatio * -1;
        double yy = (1 - 2 * ((y + 0.5) / 400)) * fovScale;

        Transformable::Point3d cameraDirection = {1, 0, 0};
        Transformable::Point3d cameraUp = {0, 0, 1};

        Transformable::Matrix3d rotationMatrix = Transformable::Matrix3d().rotateY(angleYRad).rotateX(angleXRad).rotateZ(angleZRad);
        Transformable::Point3d cameraDirectionRotated = rotationMatrix * cameraDirection;
        Transformable::Point3d cameraUpRotated = rotationMatrix * cameraUp;

        Transformable::Point3d cameraRight = cameraDirectionRotated.cross(cameraUpRotated);

        Transformable::Point3d rayDirection = cameraDirectionRotated + xx * cameraRight + yy * cameraUpRotated;
        return rayDirection;
    }


    void Scene::computeVectors(unsigned int camWidth, unsigned int camHeight, Transformable::Point3d camPos)
    {
        unsigned int i = 0;
        std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(camPos, _lights[0]->getPos());
        vector->setPrimitives(_primitives);
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[0]->getWidth(), _cameras[0]->getHeight());

        for (unsigned int y = 0; y < camHeight; y++) {
            for (unsigned int x = 0; x < camWidth; x++) {
                Display::Point2i pixelPos = Display::Point2i{(int)x, (int)y};
                vector->setPos(camPos);
                vector->setAxis(getRayDirection((int)x, (int)y, _cameras[0]));
                Raytracer::LightCalculator calculator(vector, _lights[0]);
                libGraphicHandler.addPixelToImage(createPixel(calculator.computePixel(), pixelPos));
                i++;
            }
        }
        libGraphicHandler.exportImage();
    }

    void Scene::playScene(std::string const &filename)
    {
        _filename = filename;

        if (_lights.size() == 0 || _primitives.size() == 0 || _cameras.size() == 0) {
            return;
        }
        unsigned int camWidth = _cameras[0]->getWidth();
        unsigned int camHeight = _cameras[0]->getHeight();
        Transformable::Point3d camPos = _cameras[0]->getPos();
        computeVectors(camWidth, camHeight, camPos);
    }

    Display::Pixel Scene::createPixel(Display::Color color, Display::Point2i position)
    {
        Display::Pixel pixel(color, position);
        return pixel;
    }
}
