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
            void addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera) final;
            void addLight(std::shared_ptr<Transformable::Light::ILight> light) final;
            void addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive) final;
            void addTransformation(std::shared_ptr<Transformation::ITransformation> transformation) final;

        private:
            Display::Pixel createPixel(Display::Color color, Display::Point2i position);
            void computeVectors(unsigned int camWidth, unsigned int camHeight, Transformable::Point3d camPos);
            std::string _filename;
            std::vector<std::shared_ptr<Transformable::Camera::ICamera>> _cameras;
            std::vector<std::shared_ptr<Transformable::Light::ILight>> _lights;
            std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> _primitives;
            std::vector<std::shared_ptr<Transformation::ITransformation>> _transformations;
    };
}
