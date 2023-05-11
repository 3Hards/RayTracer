/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** AMaterial header
*/

#pragma once

#include "IMaterial.hpp"

namespace Material {
    class AMaterial : public IMaterial {
        public:
            Transformable::Point3d getBaseColor() final;
            Transformable::Point3d computeSpecular(std::shared_ptr<Raytracer::IVector>) final;
        protected:
            AMaterial(Display::Color, double shininess, double reflection);
            Transformable::Point3d _baseColor;
            double _shininess;
            double _reflection;
    };
}
