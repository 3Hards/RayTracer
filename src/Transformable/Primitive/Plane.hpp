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
#include <memory>
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class Plane : public APrimitive {
            public:
                Plane(Point3d pos, double length, double width, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                std::shared_ptr<Raytracer::IVector> getNormalVector() final;

            private:
                double _depth;
                double _length;
                double _width;
        };
    }
}
