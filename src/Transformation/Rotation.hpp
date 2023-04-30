/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Rotation header
*/

#include "ITransformation.hpp"
#include "ITransformable.hpp"

namespace Transformation {
    class Rotation : public ITransformation {
        public:
            Rotation(Transformable::Point3d rotation);
            void applyTransformation(std::shared_ptr<Transformable::ITransformable>) final;
        private:
            Transformable::Point3d _rotation;
    }
}
