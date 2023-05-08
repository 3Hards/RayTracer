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
#include "3DMatrix.hpp"

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
                vector->setAxis(_cameras[0]->getRayAxis((int)x, (int)y));
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
