/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IBuilder
*/

#pragma once

namespace Scene
{
    class IBuilder
    {
        public:
            virtual ~IBuilder() = default;
            virtual void build() = 0;
            virtual void buildTransformation() = 0;
            virtual void buildTransformable() = 0;
            // virtual IScene getScene() = 0; wait add Scene class
        private:
            // IScene _scene; wait add Scene class
    };
}