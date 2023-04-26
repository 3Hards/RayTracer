/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Vector header
*/

#pragma once

#include "IVector.hpp"
#include "ATransformable.hpp"
#include "IPrimitive.hpp"

namespace Raytracer {
    class Vector : public IVector, public Transformable::ATransformable {
        public:
            Vector(Transformable::Point3f pos, Transformable::Point3f axis);
            void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) final;
            void run(std::shared_ptr<Transformable::Light::ILight> light) final;
            HittedObject getHittedObject() final;
            Display::Color getHittedColor() final;
            std::shared_ptr<IVector> getHittedNormalVector() final;
            Transformable::Point3f getPos() final;
            Transformable::Point3f getAxis() final;
            void setPos(Transformable::Point3f pos) final;
            void setAxis(Transformable::Point3f axis) final;
            Transformable::TransformableType getType() final;
        private:
            bool checkDistances(std::vector<double> &prevDistances);
            std::vector<double> getDistances();
            void moveForward();
            bool checkHitPrimitives();
            bool checkHitLight(std::shared_ptr<Transformable::Light::ILight> light);
            std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> _primitives;
            double toRad(double degree);

            HittedObject _hittedObject;
            Display::Color _hittedColor;
            std::shared_ptr<IVector> _hittedNormalVector;
    };
}