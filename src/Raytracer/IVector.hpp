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
#include "DisplayStructs.hpp"
#include "IPrimitive.hpp"

namespace Transformable {
    namespace Light {
        class ILight;
    }
}

namespace Raytracer {

    /**
     * @brief Vector interface herited by ITransormable
    */
    class IVector : public Transformable::ITransformable {
        public:

            /**
             * @brief Set the Primitives object
             * @param std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>
             * @return void
             */
            virtual void setPrimitives(std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>>) = 0;

            /**
             * @brief compute primitive color
             * @param std::vector<std::shared_ptr<Transformable::Light::ILight>>
             * @return Transformable::Point3d primitve position
             */
            virtual Display::Color computeColor(std::vector<std::shared_ptr<Transformable::Light::ILight>> lights) = 0;

            /**
             * @brief Get the Scalar R I object
             * @return double Scalar R I
             */
            virtual double getScalarRI() = 0;

            /**
             * @brief Get the Light Color object
             * @return Transformable::Point3d light color
            */
            virtual Transformable::Point3d getLightColor() = 0;
    };
}
