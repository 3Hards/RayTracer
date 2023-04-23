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
        _filename(filename)
    {}

    void Scene::addTransformable(Transformable::ITransformable *transformable)
    {
        _transformables.push_back(std::make_shared<Transformable::ITransformable *>(transformable));
    }

    void Scene::playScene(std::string const &filename)
    {
        getCamera();
        //for each vector, call the function run
    }

    void Scene::getCamera()
    {
        for (auto &transformable : _transformables) {
            if (transformable->getType() == Transformable::TransformableType::Camera) {
                _camera = std::make_shared<ICamera>(transformable);
                break;
            }
        }
    }
}
