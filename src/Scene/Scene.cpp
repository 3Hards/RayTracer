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
            handleVectorAnswer(vector);
        }
    }

    void Scene::handleVectorAnswer(std::shared_ptr<Raytracer::IVector> vector)
    {
        vector->run(_lights[0]);
        Display::Color color;
        Transformable::Point3f point;

        if (vector->getHittedObject() == Raytracer::HittedObject::PRIMITIVE) {
            color = vector->getHittedColor();
            point = vector->getPos();
            std::cout << "Intersect at " << point.x << " " << point.y << " " << point.z << std::endl;
            std::cout << "Color: " << color._r << " " << color._g << " " << color._b << std::endl;
        }
    }
}
