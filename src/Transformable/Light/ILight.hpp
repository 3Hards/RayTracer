/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ILight
*/

#pragma once

#include <memory>
#include "DisplayStructs.hpp"
#include "IVector.hpp"
#include "ITransformable.hpp"

namespace Transformable {
    namespace Light {
        /**
         * @brief Light interface
        */
        class ILight : public ITransformable {
            public:
                virtual ~ILight() = default;
                /**
                 * @brief get ambientLight Color
                 * @return ambiantLight Color
                */
                virtual Transformable::Point3d getAmbientLightColor() = 0;
                /**
                 * @brief get Light Color
                 * @return light Color
                */
                virtual Transformable::Point3d getLightColor() = 0;
                /**
                 * @brief get Light Direction
                 * @param vector is light directed ray used by omnidirectional light to return it axis as result
                 * @return light Direction
                */
                virtual Transformable::Point3d getLightDirection(std::shared_ptr<Raytracer::IVector> vector) = 0;
        };
    }
}
