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

    void Scene::playScene(std::string const &filename)
    {
        _filename = filename;
        std::vector<std::shared_ptr<Raytracer::IVector>> vectors;

        //for the v2, don't forget to handle black screen return
        if (_lights.size() == 0 || _primitives.size() == 0) {
            return;
        }
        vectors = _cameras[0]->computeVectors();
        if (vectors.size() == 0) {
            return;
        }
        for (auto &vector : vectors) {
            vector->setPrimitives(_primitives);
            handleVectorAnswer(vector->run(_lights[0]));
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
