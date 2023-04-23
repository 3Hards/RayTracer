/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

#pragma once

#include <vector>
#include <memory>
#include "IScene.hpp"
#include "ICamera.hpp"

namespace Scene {
    class Scene : public IScene {
        public:
            Scene(std::string const &filename);
            void addTransformable(std::shared_ptr<Transformable::ITransformable> transformable);
            void playScene(std::string const &filename);
        
        private:
            void handleVectorAnswer(std::tuple<bool, Display::Color, Transformable::Point3f> answer);
            std::string _filename;
            std::shared_ptr<Transformable::Camera::ICamera> _camera;
            std::shared_ptr<Transformable::Light::ILight> _light;
            //vector of primitives...
    };
}
