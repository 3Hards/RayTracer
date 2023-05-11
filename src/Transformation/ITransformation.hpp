/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** ITransformation
*/

#pragma once

#include <memory>
#include "ITransformable.hpp"

namespace Transformation {

    /**
     * @brief Interface for the transformation
    */
    class ITransformation {
        public:

            /**
             * @brief Apply the transformation to the object
             * @param std::shared_ptr<Transformable::ITransformable> object
             * @return void
            */
            virtual void applyTransformation(std::shared_ptr<Transformable::ITransformable>) = 0;
    };
}
