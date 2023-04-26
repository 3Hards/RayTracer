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
#include "DisplayStructs.hpp"

namespace Scene {
    class Scene : public IScene {
        public:
            void playScene(std::string const &filename);
            void addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera);
            void addLight(std::shared_ptr<Transformable::Light::ILight> light);
            void addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive);
            void addTransformation(std::shared_ptr<Transformation::ITransformation> transformation);

        private:
            void handleVectorAnswer(std::tuple<bool, Display::Color, Transformable::Point3f> answer);
            void addNewPixel(Display::Color color, Transformable::Point3f position);
            std::string _filename;
            std::vector<std::shared_ptr<Transformable::Camera::ICamera>> _cameras;
            std::vector<std::shared_ptr<Transformable::Light::ILight>> _lights;
            std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> _primitives;
            std::vector<std::shared_ptr<Transformation::ITransformation>> _transformations;
            std::vector<Display::Pixel> _pixels;
    };
}
