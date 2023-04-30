/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Translation header
*/

#pragma once

#include "ITransformation.hpp"

namespace Transformation {
    class Translation : public ITransformation {
        public:
            Translation(Transformable::Point3d translation);
            void applyTransformation(std::shared_ptr<Transformable::ITransformable>);
        private:
            Transformable::Point3d _translation;
    };
}
