/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** PrimiZizi
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Primitive {
        class PrimiZizi : public APrimitive {
            public:
                PrimiZizi(Point3d, double ray, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                Transformable::Point3d getNormalVector() final;
            private:
                double _ray;
        };
    }
}
