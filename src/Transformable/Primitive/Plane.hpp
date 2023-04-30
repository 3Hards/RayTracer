/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Primitive {
        class Plane : public APrimitive {
            public:
                Plane(Point3f, double length, double width, std::shared_ptr<Material::IMaterial> material);
                std::tuple<bool, Display::Color> checkHit(std::unique_ptr<Raytracer::IVector> &) final;

            private:
                double _depth;
                double _length;
                double _width;
        };
    }
}
