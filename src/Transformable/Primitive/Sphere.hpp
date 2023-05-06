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
                Sphere(Point3d, double ray, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                Point3d getNormalVector() final;
            private:
                double _ray;
        };
    }
}
