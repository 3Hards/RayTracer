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

        /**
         * @brief Primitive interface herit from ITransformable
        */
        class IPrimitive : public ITransformable {
            public:

                /**
                 * @brief Check if the vector hit the primitive
                 * @param std::shared_ptr<Raytracer::IVector> vector
                 * @return bool
                 */
                virtual bool checkHit(std::shared_ptr<Raytracer::IVector>) = 0;

                /**
                 * @brief Get the Specular object
                 * @return Transformable::Point3d
                 */
                virtual Transformable::Point3d getSpecular() = 0;

                /**
                 * @brief Get the Material Base Color object
                 * @return Transformable::Point3d
                 */
                virtual Transformable::Point3d getMaterialBaseColor() = 0;

                /**
                 * @brief Get the Pos object
                 * @return Transformable::Point3d
                 */
                virtual Transformable::Point3d getNormalVector() = 0;
        };
    }
}
