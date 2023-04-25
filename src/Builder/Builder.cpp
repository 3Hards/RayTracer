/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#include "Builder.hpp"
#include "Camera.hpp"


namespace Scene
{
    Builder::_map = {
        {"camera", &Builder::addCamera},
        {"light", &Builder::addLight},
        {"primitive", &Builder::addPrimitive},
    };
    
    Builder::Builder(std::list<libconfig::Setting *> dictionary)
    {
        _dictionary = dictionary;
    }

    void Builder::addCamera(libconfig::Setting *setting)
    {
        std::cout << "addCamera" << std::endl;
        Scene::addCamera(std::shared_ptr<Transformable::Camera::ICamera>(new Transformable::Camera::Camera()));
    }

    void Builder::addLight(libconfig::Setting *setting)
    {
        std::cout << "addLight" << std::endl;
    }

    void Builder::addPrimitive(libconfig::Setting *setting)
    {
        std::cout << "addPrimitive" << std::endl;
    }
    
    void Builder::buildTransformation()
    {
        std::string type;
        std::string name;

        for (auto &it : _dictionary) {
            it->lookupValue("type", type);
            it->lookupValue("name", name);
            std::cout << "type: " << type << std::endl;
            std::cout << "name: " << name << std::endl;
        }
    }

    void Builder::buildTransformable()
    {
        std::cout << "buildTransformable" << std::endl;
    }
}