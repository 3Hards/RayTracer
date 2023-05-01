/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#pragma once

#include "IPrimitive.hpp"
#include "ATransformable.hpp"
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class APrimitive : public IPrimitive, public ATransformable {
            public:
                APrimitive(std::shared_ptr<Material::IMaterial> material, Point3d pos, Point3d axis);
                Transformable::Point3d getSpecular() final;
                Transformable::Point3d getMaterialBaseColor() final;
                Transformable::Point3d getPos() final;
                Transformable::Point3d getAxis() final;
                void setPos(Transformable::Point3d pos) final;
                void setAxis(Transformable::Point3d axis) final;
            protected:
                std::shared_ptr<Material::IMaterial> _material;
                std::shared_ptr<Raytracer::IVector> _lastHittedVector;
        };
    }
}
