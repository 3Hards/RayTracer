/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#pragma once

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"
#include <memory>
#include "IMaterial.hpp"

namespace Transformable {
    namespace Primitive {
        class Cone : public APrimitive {
            public:
                Cone(Point3d pos, double height, double radius, Point3d Axis, std::shared_ptr<Material::IMaterial> material);
                bool checkHit(std::shared_ptr<Raytracer::IVector>) final;
                Transformable::Point3d getNormalVector() final;

            private:
                Point3d rotatePoint3D(const Point3d& point, double angleX, double angleY, double angleZ);
                bool checkHitBaseCircle(std::shared_ptr<Raytracer::IVector>);
                double _radius;
                double _height;
                Point3d _axis;
        };
    }
}
