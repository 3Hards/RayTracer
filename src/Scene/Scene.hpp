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
            void playScene(std::string const &filename);
            void addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera);
            void addLight(std::shared_ptr<Transformable::Light::ILight> light);
            //void addTransformation(std::shared_ptr<Transformable::Transformation::ITransformation> transformation);
            //void addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive);
        
        private:
            void handleVectorAnswer(std::tuple<bool, Display::Color, Transformable::Point3f> answer);
            std::string _filename;
            std::shared_ptr<Transformable::Camera::ICamera> _camera;
            std::shared_ptr<Transformable::Light::ILight> _light;
            //vector of primitives...
    };
}
