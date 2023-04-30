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
                APrimitive(std::shared_ptr<Material::IMaterial> material, Point3f pos, Point3f axis);
                Transformable::Point3f getPos() final;
                Transformable::Point3f getAxis() final;
                void setPos(Transformable::Point3f pos) final;
                void setAxis(Transformable::Point3f axis) final;
                Transformable::TransformableType getType() final;
            protected:
                std::shared_ptr<Material::IMaterial> _material;
        };
    }
}
