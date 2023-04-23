/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

#include <iostream>
#include "Scene.hpp"
#include "ITransformable.hpp"
#include "TransformableStruct.hpp"

namespace Scene {
    Scene::Scene(std::string const &filename) :
        _filename(filename),
        _camera(nullptr),
        _light(nullptr)
    {}

    void Scene::addTransformable(std::shared_ptr<Transformable::ITransformable> transformable)
    {
        if (transformable->getType() == Transformable::TransformableType::Camera &&
            _camera == nullptr) {
            _camera = std::dynamic_pointer_cast<Transformable::Camera::ICamera>(transformable);
        } else if (transformable->getType() == Transformable::TransformableType::Light &&
            _light == nullptr) {
            _light = std::dynamic_pointer_cast<Transformable::Light::ILight>(transformable);
        }
    }

    void Scene::playScene(std::string const &filename)
    {
        std::vector<std::shared_ptr<Raytracer::IVector>> _vectors = _camera->computeVectors();

        //for the v2, don't forget to handle if the light is null
        for (auto &vector : _vectors) {
            handleVectorAnswer(vector->run(_light));
        }
    }

    void Scene::handleVectorAnswer(std::tuple<bool, Display::Color, Transformable::Point3f> answer)
    {
        bool hasHitted = std::get<0>(answer);
        Display::Color color = std::get<1>(answer);
        Transformable::Point3f point = std::get<2>(answer);

        if (hasHitted) {
            std::cout << "Intersect at " << point.x << " " << point.y << " " << point.z << std::endl;
            std::cout << "Color: " << color._r << " " << color._g << " " << color._b << std::endl;
        }
    }
}
