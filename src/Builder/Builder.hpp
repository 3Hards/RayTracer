/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Builder
*/

#pragma once

#include "IBuilder.hpp"
#include <iostream>
#include "Scene.hpp"
#include <list>
#include "libconfig.h++"

namespace Scene
{
    class Builder : public IBuilder
    {
        public:
            Builder(std::list<libconfig::Setting *> dictionary);
            ~Builder() = default;
            void buildTransformation() override;
            void buildTransformable() override;
            // IScene getScene() override; wait add Scene class
        private:
            // IScene _scene; wait add Scene class
            std::list<libconfig::Setting *> _dictionary;
            static const std::unordered_map<std::string, std::function<void()>> _map;
    };
}