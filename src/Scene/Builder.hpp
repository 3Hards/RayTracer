/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#pragma once

#include <libconfig.h++>
#include <unordered_map>
#include <functional>
#include "IBuilder.hpp"
#include "IScene.hpp"
#include "Scene.hpp"
#include "IMaterial.hpp"

namespace Scene
{
    class Builder : public IBuilder
    {
        public:
            Builder(libconfig::Setting &list);
            ~Builder() = default;
            std::shared_ptr<Scene::IScene> getScene() final;
        private:
            void buildObject(libconfig::Setting& setting);
            std::shared_ptr<Material::IMaterial> createMaterial(libconfig::Setting& setting);
            void createCamera(libconfig::Setting& setting);
            void createSphere(libconfig::Setting& setting);
            void createPlane(libconfig::Setting& setting);
            void createAmbientLight(libconfig::Setting& setting);
            void createDirectionalLight(libconfig::Setting& setting);
            const std::unordered_map<std::string, std::function<void(libconfig::Setting&)>> _map = {
                {"Camera", std::bind(&Builder::createCamera, this, std::placeholders::_1)},
                {"Sphere", std::bind(&Builder::createSphere, this, std::placeholders::_1)},
                {"Ambiant", std::bind(&Builder::createAmbientLight, this, std::placeholders::_1)},
                {"Directional", std::bind(&Builder::createDirectionalLight, this, std::placeholders::_1)},
                {"Plane", std::bind(&Builder::createPlane, this, std::placeholders::_1)}
            };
            std::shared_ptr<Scene::IScene> _scene;
            libconfig::Setting& _list;

    };
}
