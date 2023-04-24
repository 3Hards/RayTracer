/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#include "Builder.hpp"


namespace Scene
{
    Builder::_map = {
        {"translate", &Builder::buildTranslate},
        {"rotate", &Builder::buildRotate},
        {"scale", &Builder::buildScale},
        {"sphere", &Builder::buildSphere},
        {"cube", &Builder::buildCube},
        {"cylinder", &Builder::buildCylinder},
        {"cone", &Builder::buildCone},
        {"plane", &Builder::buildPlane},
        {"mesh", &Builder::buildMesh},
        {"light", &Builder::buildLight},
        {"camera", &Builder::buildCamera},
        {"material", &Builder::buildMaterial},
        {"texture", &Builder::buildTexture},
        {"skybox", &Builder::buildSkybox},
        {"transformable", &Builder::buildTransformable},
        {"transformation", &Builder::buildTransformation}
    };
    
    Builder::Builder(std::list<libconfig::Setting *> dictionary)
    {
        _dictionary = dictionary;
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