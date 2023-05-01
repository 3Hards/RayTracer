/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Translation header
*/

#pragma once

#include "ITransformation.hpp"
#include "TransformableStruct.hpp"

namespace Transformation {
    class Translation : public ITransformation {
        public:
            Translation(Transformable::Point3f translation);
            void applyTransformation(std::shared_ptr<Transformable::ITransformable>);
        private:
            Transformable::Point3f _translation;
    };
}
