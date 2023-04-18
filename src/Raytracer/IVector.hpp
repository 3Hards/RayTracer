/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IVector
*/

#pragma once

#include <vector>
#include <memory>
#include "ITransformable.hpp"

namespace Transformable {
    class IPrimitive {
        std::tuple<bool, Color> checkHit(std::shared_ptr<Raytracer::IVector>);
    };
    class ILight {

    };
}
namespace Material {
    class IMaterial {};
}

namespace Raytracer {
    class IVector : public Transformable::ITransformable {
        public:
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::IPrimitive>>) = 0;
            virtual std::tuple<bool, Material::IMaterial, Transformable::Point3f> run(Transformable::ILight) = 0;
    };
}
