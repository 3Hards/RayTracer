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
            Vector(Transformable::Point3f pos, Transformable::Point3f axis);
            void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>);
            std::tuple<bool, Display::Color, Transformable::Point3f> run(Transformable::Light::ILight);
            Transformable::Point3f getPos();
            Transformable::Point3f getAxis();
            void setPos(Transformable::Point3f pos);
            void setAxis(Transformable::Point3f axis);
            Transformable::TransformableType getType();
        private:
            void moveForward();
            std::tuple<bool, Display::Color> checkHit();
            std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> _primitives;
            double toRad(double degree);
    };
}