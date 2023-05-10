/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#include <iostream>
#include "Builder.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "FlatColor.hpp"
#include "Ambient.hpp"
#include "Directional.hpp"
#include "Cylinder.hpp"

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
        int x, y, z;
        int fov;
        const libconfig::Setting &axis = setting["axis"];
        int ax, ay, az;
        const libconfig::Setting &res = setting["resolution"];
        int rx, ry;
        std::string transType;

        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        fov = setting.lookup("fov");
        ax = axis.lookup("x");
        ay = axis.lookup("y");
        az = axis.lookup("z");
        rx = res.lookup("x");
        ry = res.lookup("y");
        std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3d{(double)x, (double)y, (double)z}, Transformable::Point3d{(double)ax, (double)ay, (double)az}, (double)rx, (double)ry, (double)fov);
        _scene->addCamera(camera);
        std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 255, 255});
        std::shared_ptr<Transformable::Primitive::IPrimitive> cylinder = std::make_shared<Transformable::Primitive::Cylinder>(Transformable::Point3d{(double)10, (double)0, (double)0}, 5, 5, material);
        _scene->addPrimitive(cylinder);
        std::cout << "Camera created and Cylender" << std::endl;
    }

    void Builder::createSphere(libconfig::Setting& setting)
    {
        int x, y, z;
        std::string type = setting.lookup("type");
        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        int r = setting.lookup("r");
        const libconfig::Setting& color = setting.lookup("color");
        int red = color.lookup("r");
        int green = color.lookup("g");
        int blue = color.lookup("b");
        std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{red, green, blue});
        std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{(double)x, (double)y, (double)z}, r, material);
        _scene->addPrimitive(sphere);
    }

    void Builder::createAmbientLight(libconfig::Setting& setting)
    {
        int x, y, z;
        double brightness;
        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        brightness = setting.lookup("brightness");
        std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambient>(Display::Color{255, 255, 255}, brightness, Transformable::Point3d{(double)x, (double)y, (double)z});
        _scene->addLight(light);
    }

    void Builder::createDirectionalLight(libconfig::Setting& setting)
    {
        int x, y, z;
        double brightness;
        int ax, ay, az;
        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        brightness = setting.lookup("brightness");
        const libconfig::Setting& axis = setting.lookup("axis");
        ax = axis.lookup("x");
        ay = axis.lookup("y");
        az = axis.lookup("z");
        std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Directional>(Display::Color{255, 255, 255},
            brightness, Transformable::Point3d{(double)x, (double)y, (double)z}, Transformable::Point3d{(double)ax, (double)ay, (double)az});
        _scene->addLight(light);
    }

}
