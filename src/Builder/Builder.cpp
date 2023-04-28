/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#include "Builder.hpp"
#include <iostream>
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "FlatColor.hpp"
// #include "AmbientLight.hpp"

namespace Scene
{
    Builder::Builder(libconfig::Setting& list) : _list(list)
    {
        _scene = std::make_shared<Scene>();
        for (int i = 0; i < _list.getLength(); i++) {
            buildObject(_list[i]);
        }
    }

    std::shared_ptr<Scene::IScene> Builder::getScene()
    {
        return _scene;
    }

    //Private

    void Builder::buildObject(libconfig::Setting& setting)
    {
        std::string type;
        setting.lookupValue("type", type);
        _map.at(type)(setting);
    }

    void Builder::createCamera(libconfig::Setting& setting)
    {
            double x, y, z;
            int fov;
            const libconfig::Setting &axis = setting["axis"];
            double ax, ay, az;
            const libconfig::Setting &res = setting["resolution"];
            double rx, ry;
            const libconfig::Setting &trans = setting["transformation"];
            std::string transType;
            double tx, ty, tz;

            setting.lookupValue("x", x);
            setting.lookupValue("y", y);
            setting.lookupValue("z", z);
            setting.lookupValue("fov", fov);
            axis.lookupValue("x", ax);
            axis.lookupValue("y", ay);
            axis.lookupValue("z", az);
            res.lookupValue("x", rx);
            res.lookupValue("y", ry);
            trans.lookupValue("type", transType);
            trans.lookupValue("x", tx);
            trans.lookupValue("y", ty);
            trans.lookupValue("z", tz);
            std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3f{x, y, z}, Transformable::Point3f{ax, ay, az}, rx, ry, fov);
            _scene->addCamera(camera);
    }

    void Builder::createSphere(libconfig::Setting& setting)
    {
            double x, y, z, r;
            const libconfig::Setting& color = setting["color"];
            int cr, cg, cb;
            color.lookupValue("r", cr);
            color.lookupValue("g", cg);
            color.lookupValue("b", cb);
            setting.lookupValue("x", x);
            setting.lookupValue("y", y);
            setting.lookupValue("z", z);
            setting.lookupValue("r", r);
            std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{cr, cg, cb});
            std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3f{x, y, z}, r, material);
            _scene->addPrimitive(sphere);
    }

    // void Builder::createAmbientLight(libconfig::Setting& setting)
    // {
    //         int x, y, z;
    //         double brightness;
    //         setting.lookupValue("x", x);
    //         setting.lookupValue("y", y);
    //         setting.lookupValue("z", z);
    //         setting.lookupValue("brightness", brightness);
    //         std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::AmbientLight>(Transformable::Point3f{x, y, z}, brightness);
    //         _scene->addLight(light);
    // }
}