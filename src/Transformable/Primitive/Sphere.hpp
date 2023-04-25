/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Primitive {
        class Sphere : public APrimitive {
            public:
                Sphere(Point3f, float ray, std::shared_ptr<Material::IMaterial> material);
                std::tuple<bool, Display::Color> checkHit(std::unique_ptr<Raytracer::IVector> &) final;

            private:
                double _ray;
        };
    }
}
