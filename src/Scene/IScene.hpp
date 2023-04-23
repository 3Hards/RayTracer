/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IScene
*/

#pragma once

#include <string>
#include "ITransformable.hpp"

namespace Scene {
    class IScene {
        public:
            virtual ~IScene() = default;
            virtual void addTransformable(Transformable::ITransformable *transformable) = 0;
            virtual void playScene(std::string const &filename) = 0;
            //virtual void addTransformation(ITransformation *transformation) = 0;
    };
}
