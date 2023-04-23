/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ATransformable
*/

#include "ITransformable.hpp"
#include "DisplayStructs.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Primitive {
        class IPrimitive : public ITransformable {
            public:
                std::tuple<bool, Display::Color> checkHit(Raytracer::IVector);
        };
    }
}
