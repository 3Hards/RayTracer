/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#pragma once

#include <memory>
#include "ITransformable.hpp"
#include "DisplayStructs.hpp"

namespace Raytracer {
    class IVector;
}

namespace Transformable {
    namespace Primitive {
        class IPrimitive : public ITransformable {
            public:
                virtual bool checkHit(std::shared_ptr<Raytracer::IVector>) = 0;
                virtual Transformable::Point3d getSpecular() = 0;
                virtual Transformable::Point3d getMaterialBaseColor() = 0;
                virtual Point3d getNormalVector() = 0;
        };
    }
}
