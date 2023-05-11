/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IVector
*/

#pragma once

#include "IVector.hpp"
#include "DisplayStructs.hpp"

namespace Material {

    /**
     * @brief Material interface
    */
    class IMaterial {
        public:

            /**
             * @brief Get the Base Color object
             * 
             * @return Transformable::Point3d 
             */
            virtual Transformable::Point3d getBaseColor() = 0;

            /**
             * @brief Compute specular intensity
             * 
             * @param vector 
             * @return Transformable::Point3d 
             */
            virtual Transformable::Point3d computeSpecular(std::shared_ptr<Raytracer::IVector>) = 0;
    };
}
