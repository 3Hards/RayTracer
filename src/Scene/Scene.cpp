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

    Transformable::Point3d getRayDirection(int x, int y)
    {
        //camres = 1920 1080
        //camFov = 90
        //camPos = 0 0 0
        //camDirection = 0 0 1
        //camUp = 0 1 0

        double fovScale = std::tan((90 * M_PI / 180) / 2);
        double aspectRatio = 1920 / 1080;
        double xx = (2 * ((double)x + 0.5) / 1920 - 1) * fovScale * aspectRatio;
        double yy = (1 - 2 * ((double)y + 0.5) / 1080) * fovScale;

        Transformable::Point3d cameraDirection = {0, 0, 1};
        Transformable::Point3d cameraUp = {0, 1, 0};
        Transformable::Point3d rayDir = (cameraDirection + (cameraUp * yy) + cameraUp.cross(cameraDirection) * xx).normalize();
        return rayDir;
    }

    void Scene::computeVectors(unsigned int camWidth, unsigned int camHeight, Transformable::Point3d camPos)
    {
        unsigned int i = 0;
        std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(camPos, _lights[0]->getPos());
        vector->setPrimitives(_primitives);
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[0]->getWidth(), _cameras[0]->getHeight());

        for (unsigned int y = 0; y < camHeight; y++) {
            for (unsigned int x = 0; x < camWidth; x++) {
                Transformable::Point3d pos = {0, 0, 0};
                Display::Point2i pixelPos = Display::Point2i{(int)x, (int)y};
                vector->setPos(pos);
                vector->setAxis(getRayDirection((int)x, (int)y));
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
