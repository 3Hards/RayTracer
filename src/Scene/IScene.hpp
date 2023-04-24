/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IScene
*/

#pragma once

#include <memory>
#include <string>
#include "ILight.hpp"
#include "ICamera.hpp"
#include "IPrimitive.hpp"

namespace Scene {
    class IScene {
        public:
            virtual ~IScene() = default;
            virtual void playScene(std::string const &filename) = 0;
            virtual void addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera) = 0;
            virtual void addLight(std::shared_ptr<Transformable::Light::ILight> light) = 0;
            virtual void addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive) = 0;
            //virtual void addTransformation(std::shared_ptr<Transformable::Transformation::ITransformation> transformation) = 0;
    };
}
