/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** primiZizi
*/

#include "../AppApi.hpp"
#include "IPrimitive.hpp"
#include "PrimiZizi.hpp"

#ifdef _WIN32
    #define EXPORT __declspec(dllexport)
#else
    #define EXPORT
#endif

extern "C"
{
    /**
    * @brief The Api cpp
    *
    * The api cpp is the extern C function that will be called by the raytracer
    *
    */
    EXPORT Transformable::Primitive::IPrimitive *createPrimitive(Transformable::Point3d pos, double ray, Material::IMaterial *material)
    {
        std::shared_ptr<Material::IMaterial> materialShared = std::shared_ptr<Material::IMaterial>(material);
        Transformable::Primitive::PrimiZizi *primitive = new Transformable::Primitive::PrimiZizi(pos, ray, materialShared);
        Transformable::Primitive::IPrimitive* primitivePtr = primitive;
        return primitivePtr;
    }

    EXPORT void deletePrimitive(Transformable::Primitive::IPrimitive *primitiveModule)
    {
        if (auto module = dynamic_cast<Transformable::Primitive::PrimiZizi*>(primitiveModule)) {
            delete module;
        }
    }

    /**
     * @brief getName 
     * 
     * @return const char *
     * 
     * @attention return the name of the plugin
     * 
    */
    EXPORT const char *getName()
    {
        return "primiBite";
    }

    /**
     * @brief getType 
     * 
     * @return LibType
     * 
     * @attention return the type of the lib
     * 
    */
    EXPORT App::PluginType getType()
    {
        return App::PluginType::PRIMITIVE;
    }
}
