/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cylinder
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Primitive {
        class Cylinder : public APrimitive {
            public:
                Cylinder(Point3d pos, Point3d axis, double ray, double height, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                Transformable::Point3d getNormalVector() final;
            private:
                double _ray;
                double _height;
                Point3d _axis;
        };
    }
}
