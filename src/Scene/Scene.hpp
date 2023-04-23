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
#include "IVector.hpp"

namespace Transformable {
    namespace Light {
        class ILight {
            public:
                virtual ~ILight() = default;
        };

        class Light : public ILight {
            public:
                Light() = default;
        };
    }
}

namespace Scene {
    class Scene : public IScene {
        public:
            Scene(std::string const &filename);
            void addTransformable(std::shared_ptr<Transformable::ITransformable> transformable);
            void playScene(std::string const &filename);
        
        private:
            std::string _filename;
            std::shared_ptr<Transformable::Camera::ICamera> _camera;
            std::shared_ptr<Transformable::Light::ILight> _light;
            //vector of primitives...
    };
}