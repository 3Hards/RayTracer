/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Sphere
*/

#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "APrimitive.hpp"
#include "ATransformable.hpp"
#include "IVector.hpp"

namespace Transformable {
    namespace Primitive {
        class Sphere : public APrimitive {
            public:
                Sphere(Point3f, float ray, Material::IMaterial);
                ~Sphere();
                std::tuple<bool, Display::Color> checkHit(Raytracer::IVector &);
                
            private:
                double _ray;
                Point3f _position;

        };
    }
}


#endif /* !SPHERE_HPP_ */
