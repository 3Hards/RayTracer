/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"
#include <memory>
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class Cone : public APrimitive {
            public:
                Cone(Point3d, double ray, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                Transformable::Point3d getNormalVector() final;

            private:
                double _ray;
                double _height;
                double _cosAngle;
        };
    }
}

