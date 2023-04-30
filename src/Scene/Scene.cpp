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

    void Scene::computeVectors(unsigned int camWidth, unsigned int camHeight, Transformable::Point3d camPos, std::vector<Transformable::Point3d> axis)
    {
        unsigned int i = 0;
        std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(camPos, axis[0]);
        vector->setPrimitives(_primitives);
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[0]->getWidth(), _cameras[0]->getHeight());

        for (unsigned int y = 0; y < camHeight; y++) {
            for (unsigned int x = 0; x < camWidth && i <= axis.size(); x++) {
                Transformable::Point3d pos = {camPos.x + x, camPos.y + y, camPos.z};
                Display::Point2i pixelPos = {(int)x, (int)y};
                vector->setPos(pos);
                vector->setAxis(axis[i]);
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
        std::vector<Transformable::Point3d> axis;

        if (_lights.size() == 0 || _primitives.size() == 0 || _cameras.size() == 0) {
            return;
        }
        axis = _cameras[0]->computeAxis();
        if (axis.size() == 0) {
            return;
        }
        unsigned int camWidth = _cameras[0]->getWidth();
        unsigned int camHeight = _cameras[0]->getHeight();
        Transformable::Point3d camPos = _cameras[0]->getPos();
        computeVectors(camWidth, camHeight, camPos, axis);
    }

    Display::Pixel Scene::createPixel(Display::Color color, Display::Point2i position)
    {
        Display::Pixel pixel;

        pixel._color = color;
        pixel._pos._x = position._x;
        pixel._pos._y = position._y;
        return pixel;
    }
}
