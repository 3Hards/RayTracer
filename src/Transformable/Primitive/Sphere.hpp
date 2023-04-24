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
                Sphere(Point3f, float ray, Material::IMaterial);
                std::tuple<bool, Display::Color> checkHit(Raytracer::IVector &);

            private:
                double _ray;
                Point3f _position;
                Material::IMaterial _material;
        };
    }
}
