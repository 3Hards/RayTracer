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
#include "Plane.hpp"

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

    void Builder::createPlane(libconfig::Setting& setting)
    {
        int x, y, z;
        int AxisX, AxisY, AxisZ;
        int width, length;
        std::string type = setting.lookup("type");
        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        AxisX = setting.lookup("AxisX");
        AxisY = setting.lookup("AxisY");
        AxisZ = setting.lookup("AxisZ");
        width = setting.lookup("width");
        length = setting.lookup("length");
        const libconfig::Setting& color = setting.lookup("color");
        int red = color.lookup("r");
        int green = color.lookup("g");
        int blue = color.lookup("b");
        std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{red, green, blue});
        std::shared_ptr<Transformable::Primitive::IPrimitive> plane = std::make_shared<Transformable::Primitive::Plane>(Transformable::Point3d{(double)x, (double)y, (double)z}, width, length, Transformable::Point3d{(double)AxisX, (double)AxisY, (double)AxisZ}, material);
        _scene->addPrimitive(plane);
    }
}
