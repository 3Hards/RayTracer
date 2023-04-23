/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "IPrimitive.hpp"
#include "ATransformable.hpp"
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class APrimitive : public IPrimitive, public ATransformable {
            public:
                APrimitive(Material::IMaterial material, Point3f pos, Point3f axis);
            protected:
                Material::IMaterial _material;
        };
    }
}
