/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IBuilder
*/

#pragma once

#include "IScene.hpp"
#include <memory>

namespace Scene
{
    class IBuilder
    {
        public:
            virtual std::shared_ptr<Scene::IScene> getScene() = 0;
    };
}