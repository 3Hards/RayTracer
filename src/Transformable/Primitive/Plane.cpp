/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** Plane
*/

#include <cmath>
#include "Plane.hpp"
#include "Vector.hpp"
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace Transformable {
    namespace Primitive {

        Transformable::Point3d rotateVector(const Transformable::Point3d& vector, double angleX, double angleY, double angleZ)
        {
            Transformable::Point3d rotatedX = {
                vector.x, std::cos(angleX) * vector.y - std::sin(angleX) * vector.z,
                std::sin(angleX) * vector.y + std::cos(angleX) * vector.z
            };
            Transformable::Point3d rotatedY = {
                std::cos(angleY) * rotatedX.x + std::sin(angleY) * rotatedX.z, rotatedX.y,
                -std::sin(angleY) * rotatedX.x + std::cos(angleY) * rotatedX.z
            };
            Transformable::Point3d rotatedZ = {
                std::cos(angleZ) * rotatedY.x - std::sin(angleZ) * rotatedY.y,
                std::sin(angleZ) * rotatedY.x + std::cos(angleZ) * rotatedY.y,
                rotatedY.z
            };
            return rotatedZ;
        }

        Plane::Plane(Point3d pos, double length, double width, Point3d axis, std::shared_ptr<Material::IMaterial> material)
            : Transformable::Primitive::APrimitive(material, pos, axis), _length(length), _width(width)
        {
            _normal = {0.0, 0.0, 1.0};

            double angleX = getAxis().x * M_PI / 180.0;
            double angleY = getAxis().y * M_PI / 180.0;
            double angleZ = getAxis().z * M_PI / 180.0;
            _normal = rotateVector(_normal, angleX, angleY, angleZ);
            Point3d dimensions = {_length, _width, 0.0};
            dimensions = rotateVector(dimensions, angleX, angleY, angleZ);
            _length = dimensions.x;
            _width = dimensions.y;
            double lengthh = _normal.len();
            _normal = Point3d {_normal.x / lengthh, _normal.y / lengthh, _normal.z / lengthh};
        }

        bool Plane::checkHit(std::shared_ptr<Raytracer::IVector> vector)
        {
            Point3d vectorPos = vector->getPos();
            Point3d vectorAxis = vector->getAxis();
            Point3d rotatedVectorPos = rotateVector(vectorPos - getPos(), -getAxis().x, -getAxis().y, -getAxis().z);
            Point3d rotatedVectorAxis = rotateVector(vectorAxis, -getAxis().x, -getAxis().y, -getAxis().z);
            double dotProduct = rotatedVectorAxis.dot(_normal);

            if (dotProduct == 0) {
                return false;
            }
            double t = -rotatedVectorPos.dot(_normal) / dotProduct;
            if (t < 0) {
                return false;
            }
            Point3d hitPos = vectorPos + vectorAxis * t;
            Point3d localHitPos = rotateVector(hitPos - getPos(), -getAxis().x, -getAxis().y, -getAxis().z);
            if (localHitPos.x >= 0 && localHitPos.x <= _length && localHitPos.y >= 0 && localHitPos.y <= _width) {
                _lastHittedVector = vector;
                vector->setPos(hitPos);
                return true;
            }
            return false;
        }

        Transformable::Point3d Plane::getNormalVector()
        {
            return _normal;
        }

    }
}
