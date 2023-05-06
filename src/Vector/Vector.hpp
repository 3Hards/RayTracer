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
#include "ILight.hpp"

namespace Raytracer {
    enum class State {
        INCIDENT,
        LIGHT,
        STOP
    };

    class Vector : public IVector, public Transformable::ATransformable, public std::enable_shared_from_this<Raytracer::IVector> {
        public:
            Vector(
                std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>,
                std::vector<std::shared_ptr<Transformable::Light::ILight>>);
            Vector(Transformable::Point3d pos, Transformable::Point3d axis,
                std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>,
                std::vector<std::shared_ptr<Transformable::Light::ILight>>);
            Display::Color computeColor() final;
            double getScalarRI() final;
            Transformable::Point3d getLightColor() final;
            Transformable::Point3d getPos() final;
            Transformable::Point3d getAxis() final;
            void setPos(Transformable::Point3d pos) final;
            void setAxis(Transformable::Point3d axis) final;
        private:
            void compute();
            void run();
            void checkDistances();
            void updateDistances();
            void moveForward();
            void hitPrimitive();
            void checkHitPrimitives();
            void checkHitLight();

            double _scalarNL;
            Display::Color _res;
            Transformable::Point3d _incident;
            State _state;
            std::vector<double> _distances;
            std::shared_ptr<Transformable::Primitive::IPrimitive> _hittedPrimitive;
            Transformable::Point3d _normal;
            std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> _primitives;
            std::vector<std::shared_ptr<Transformable::Light::ILight>> _lights;
    };
}
