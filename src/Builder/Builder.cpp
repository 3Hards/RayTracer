/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#include "Builder.hpp"


namespace Scene
{
    Builder::Builder(std::list<libconfig::Setting *> dictionary)
    {
        _dictionary = dictionary;
    }
    
    void Builder::buildTransformation()
    {
        // accedes a each value of _dictionary and create a transformation new()
        // with libconfig
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