/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector header
*/

#pragma once

#include "IVector.hpp"
#include "ATransformable.hpp"

namespace Raytracer {
    class Vector : public IVector, public Transformable::ATransformable {
        public:
            Vector();
            void setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>>);
            std::tuple<bool, Display::Color, Transformable::Point3f> run(Transformable::ILight);
        private:
            void moveForward();
            std::tuple<bool, Display::Color> checkHit();
            std::vector<std::shared_ptr<Transformable::IPrimitive>> _primitives;
    };
}