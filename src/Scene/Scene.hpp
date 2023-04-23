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
            void addTransformable(Transformable::ITransformable *transformable);
            void playScene(std::string const &filename);
        
        private:
            void getCamera();

            std::vector<std::shared_ptr<Transformable::ITransformable *>> _transformables;
            std::string _filename;
            std::shared_ptr<ICamera> _camera;
    };
}
