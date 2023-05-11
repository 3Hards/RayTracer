/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IBuilder
*/

#pragma once

#include <memory>
#include "IScene.hpp"

namespace Scene
{
    /**
     * @brief Interface for the builder
    */
    class IBuilder
    {
        public:
            /**
             * @brief Get the Scene
             * @return std::shared_ptr<Scene::IScene> Scene
            */
            virtual std::shared_ptr<Scene::IScene> getScene() = 0;
    };
}
