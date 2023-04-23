/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

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

        for (auto &vector : _vectors) {
            vector->run(_light);
        }
    }
}
