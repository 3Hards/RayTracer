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

    void Scene::playScene(std::string const &filename)
    {
        int i = 0;
        _filename = filename;
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[0]->getWidth(), _cameras[0]->getHeight());
        std::vector<Transformable::Point3d> axis;

        if (_lights.size() == 0 || _primitives.size() == 0) {
            return;
        }
        axis = _cameras[0]->computeAxis();
        if (axis.size() == 0) {
            return;
        }
        unsigned int camWidth = _cameras[0]->getWidth();
        unsigned int camHeight = _cameras[0]->getHeight();
        Transformable::Point3d camPos = _cameras[0]->getPos();

        for (unsigned int y = 0; y < camHeight; y++) {
            for (unsigned int x = 0; x < camWidth && axis.size() <= i; x++) {
                Transformable::Point3d pos = {camPos.x + x, camPos.y + y, camPos.z};
                std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(pos, axis[i]);
                Raytracer::LightCalculator calculator(vector, _lights[0]);
                libGraphicHandler.addPixelToImage(createPixel(calculator.computePixel(), vector->getPos()));
                i++;
            }
        }
        libGraphicHandler.exportImage();
    }

    Display::Pixel Scene::createPixel(Display::Color color, Transformable::Point3d position)
    {
        Display::Pixel pixel;

        pixel._color = color;
        pixel._pos._x = (int)position.x;
        pixel._pos._y = (int)position.y;
        return pixel;
    }
}
