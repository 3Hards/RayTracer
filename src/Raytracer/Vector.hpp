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
    enum class State {
        INCIDENT,
        LIGHT,
        STOP
    };

    class Vector : public IVector, public Transformable::ATransformable, public std::enable_shared_from_this<Raytracer::IVector> {
        public:
            Vector(Transformable::Point3d pos, Transformable::Point3d axis);
            void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) final;
            Display::Color computeColor(std::shared_ptr<Transformable::Light::ILight> light) final;
            double getScalarRI() final;
            Transformable::Point3d getLightColor() final;
            Transformable::Point3d getPos() final;
            Transformable::Point3d getAxis() final;
            void setPos(Transformable::Point3d pos) final;
            void setAxis(Transformable::Point3d axis) final;
        private:
            double computeScalarProduct(Transformable::Point3d fst, Transformable::Point3d scd);
            void compute();
            void run();
            Transformable::Point3d normalize(Transformable::Point3d);
            Transformable::Point3d normalize();
            void hitPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive>);
            void checkHitPrimitives();
            void checkHitLight();

            double _scalarNL;
            Display::Color _res;
            Transformable::Point3d _incident;
            State _state;
            std::vector<double> _distances;
            std::shared_ptr<Transformable::Light::ILight> _light;
            std::shared_ptr<Transformable::Primitive::IPrimitive> _hittedPrimitive;
            Transformable::Point3d _normal;
            std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> _primitives;
    };
}
