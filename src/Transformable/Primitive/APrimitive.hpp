/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "IPrimitive.hpp"
#include "ATransformable.hpp"

namespace Transformable {
    namespace Primitive {
        class APrimitive : public IPrimitive, public ATransformable {
            public:
                APrimitive(Raytracer::IMaterial material);
            protected:
                Raytracer::IMaterial _material;
        }
    }
}
