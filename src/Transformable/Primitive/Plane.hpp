/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Plane
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"
#include <memory>
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class Plane : public APrimitive {
            public:
                Plane(Point3d pos, double length, double width, Point3d axis, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                Transformable::Point3d getNormalVector() final;

            private:
                Point3d rotatePoint3D(const Point3d& point, double angleX, double angleY, double angleZ);
                double _length;
                double _width;
                Transformable::Point3d _normal;
        };
    }
}
