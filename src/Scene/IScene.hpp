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
#include "ILibGraphicHandler.hpp"
#include "ITransformation.hpp"

namespace Scene {

    /**
     * @brief Interface for the scene
    */
    class IScene {
        public:

            /**
             * @brief Scene destructor
            */
            virtual ~IScene() = default;

            /**
             * @brief Play the scene
             * @param filename
             * @return void
            */
            virtual void playScene(std::string const &filename) = 0;

            /**
             * @brief Add a camera to the scene
             * @param camera
             * @return void
            */
            virtual void addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera) = 0;

            /**
             * @brief Add a light to the scene
             * @param light
             * @return void
            */
            virtual void addLight(std::shared_ptr<Transformable::Light::ILight> light) = 0;

            /**
             * @brief Add a primitive to the scene
             * @param primitive
             * @return void
            */
            virtual void addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive) = 0;

            /**
             * @brief Add a transformation to the scene
             * @param transformation
             * @return void
            */
            virtual void addTransformation(std::shared_ptr<Transformation::ITransformation> transformation) = 0;
    };
}
