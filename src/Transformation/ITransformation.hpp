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
    class ITransformation {
        public:
            virtual void applyTransformation(std::shared_ptr<Transformable::ITransformable>) = 0;
    };
}
