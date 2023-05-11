/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#include <iostream>
#include <filesystem>
#include "Builder.hpp"
#include "Scene.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "FlatColor.hpp"
#include "Ambient.hpp"
#include "Plane.hpp"
#include "Directional.hpp"
#include "LibLoader.hpp"
#include "Cylinder.hpp"

namespace App {
    enum class PluginType {
        PRIMITIVE,
        MATERIAL,
        LIGHT,
        CAMERA,
        BUILDER,
        DIRECTOR,
        SCENE,
        TRANSFORMATION,
        VECTOR
    };
}

namespace Scene
{
    Builder::Builder(libconfig::Setting& list) : _list(list)
    {
        _scene = std::make_shared<Scene>();
        loadPluginsPath();
        for (int i = 0; i < _list.getLength(); i++) {
            buildObject(_list[i]);
        }
    }

    std::shared_ptr<Scene::IScene> Builder::getScene()
    {
        return _scene;
    }

    void Builder::buildObject(libconfig::Setting& setting)
    {
        std::string type;
        setting.lookupValue("type", type);
        try {
            _map.at(type)(setting);
        } catch (std::out_of_range &e) {
            throw std::runtime_error("Unknown type : " + type);
        } catch (libconfig::SettingNotFoundException &e) {
            throw std::runtime_error("Missing settings in " + type);
        }
    }

    void Builder::createCylinder(libconfig::Setting &setting)
    {
        int x, y, z;
        int ray;
        int height;
        const libconfig::Setting &axis = setting["axis"];
        int ax, ay, az;
        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        ray = setting.lookup("ray");
        height = setting.lookup("height");
        ax = axis.lookup("x");
        ay = axis.lookup("y");
        az = axis.lookup("z");
        const libconfig::Setting &color = setting["color"];
        int r, g, b;
        r = color.lookup("r");
        g = color.lookup("g");
        b = color.lookup("b");
        std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{r, g, b});
        std::shared_ptr<Transformable::Primitive::IPrimitive> cylinder = std::make_shared<Transformable::Primitive::Cylinder>(Transformable::Point3d{(double)x, (double)y, (double)z}, Transformable::Point3d{(double)ax, (double)ay, (double)az}, (double)ray, (double)height, material);
        _scene->addPrimitive(cylinder);
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

    void Builder::loadPluginsPath()
    {
        std::string path = "./plugins";
        #ifdef _WIN32
            std::string fileExtension = ".dll";
        #elif __linux__
            std::string fileExtension = ".so";
        #endif

        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() == fileExtension) {
                const std::string _filePath = entry.path().string();
                auto pluginTypeFunc = App::LibLoader<App::PluginType>::getInstance().getSymbol("getType", _filePath);
                if (pluginTypeFunc == nullptr)
                {
                    throw std::runtime_error("Error while loading plugin type");
                } else if (pluginTypeFunc() == App::PluginType::PRIMITIVE) {
                    _pluginsPath.push_back(_filePath);
                }
                _pluginsPath.push_back(_filePath);
            }
        }
    }

    void Builder::addCustomPrimitive(libconfig::Setting& setting)
    {
        int x, y, z;
        std::string type = setting.lookup("type");
        std::string name = setting.lookup("name");
        std::string path = "";

        for (auto &pluginPath : _pluginsPath) {
            auto nameFunc = App::LibLoader<char *>::getInstance().getSymbol("getName", pluginPath);
            if (nameFunc == nullptr) {
                throw std::runtime_error("Error while loading plugin name");
            }
            if (nameFunc() == name) {
                path = pluginPath;
                break;
            } else {
                continue;
            }
        }
        if (path == "") {
            throw std::runtime_error("Plugin not found");
        }
        x = setting.lookup("x");
        y = setting.lookup("y");
        z = setting.lookup("z");
        int r = setting.lookup("r");
        const libconfig::Setting& color = setting.lookup("color");
        int red = color.lookup("r");
        int green = color.lookup("g");
        int blue = color.lookup("b");

        Material::FlatColor *material = new Material::FlatColor(Display::Color{red, green, blue});
        auto primitiveCreator = App::LibLoader<Transformable::Primitive::IPrimitive *, Transformable::Point3d, double, Material::IMaterial*>::getInstance().getSymbol("createPrimitive", path);
        if (primitiveCreator == nullptr || material == NULL) {
                throw std::runtime_error("Error while loading primitive creator");
        }
        Transformable::Primitive::IPrimitive *pluginPrimitive = primitiveCreator(Transformable::Point3d{(double)x, (double)y, (double)z}, r, material);
        if (pluginPrimitive == nullptr) {
            throw std::runtime_error("Primitive creation failed");
        }
        std::shared_ptr<Transformable::Primitive::IPrimitive> customPrimitive(pluginPrimitive);
        _scene->addPrimitive(customPrimitive);
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
        const libconfig::Setting& color = setting.lookup("color");
        int r = color.lookup("r");
        int g = color.lookup("g");
        int b = color.lookup("b");
        std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambient>(Display::Color{r, g, b}, brightness, Transformable::Point3d{(double)x, (double)y, (double)z});
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
