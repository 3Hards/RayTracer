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

        Plane::Plane(Point3d pos, double length, double width, Point3d axis, std::shared_ptr<Material::IMaterial> material)
            : Transformable::Primitive::APrimitive(material, pos, axis), _length(length), _width(width)
        {
            _normal = {0.0, 0.0, 0.0};

            double angleX = getAxis().x * M_PI / 180.0;
            double angleY = getAxis().y * M_PI / 180.0;
            double angleZ = getAxis().z * M_PI / 180.0;

            Point3d pointB = getPos();
            Point3d pointR = {getPos().x + _length / 2.0, getPos().y, getPos().z};
            Point3d pointS = {getPos().x, getPos().y + _width / 2.0, getPos().z};

            Point3d rotatedPointB = rotatePoint3D(pointB, angleX, angleY, angleZ);
            Point3d rotatedPointR = rotatePoint3D(pointR, angleX, angleY, angleZ);
            Point3d rotatedPointS = rotatePoint3D(pointS, angleX, angleY, angleZ);

            Point3d vectorBR = rotatedPointR - rotatedPointB;
            Point3d vectorBS = rotatedPointS - rotatedPointB;

            _normal = vectorBR.cross(vectorBS);
            _normal.normalize();
        }

        Point3d Plane::rotatePoint3D(const Point3d& point, double angleX, double angleY, double angleZ)
        {
            Point3d res = {0, 0, 0};

            double rotatedX = point.x;
            double rotatedY = std::cos(angleX) * point.y - std::sin(angleX) * point.z;
            double rotatedZ = std::sin(angleX) * point.y + std::cos(angleX) * point.z;
            double computeX = std::cos(angleY) * rotatedX + std::sin(angleY) * rotatedZ;
            double computeY = rotatedY;
            double computeZ = -std::sin(angleY) * rotatedX + std::cos(angleY) * rotatedZ;

            res = {
                std::cos(angleZ) * computeX - std::sin(angleZ) * computeY,
                std::sin(angleZ) * computeX + std::cos(angleZ) * computeY,
                computeZ
            };

            return res;
        }

        bool Plane::checkHit(std::shared_ptr<Raytracer::IVector> vector)
        {
            Point3d vectorPos = vector->getPos();
            Point3d vectorAxis = vector->getAxis();
            double dotProduct = vectorAxis.dot(_normal);

            if (dotProduct == 0) {
                return false;
            }
            double t = (_normal.dot(getPos() - vectorPos)) / dotProduct;
            if (t < 0) {
                return false;
            }
            Point3d hitPos = vectorPos + vectorAxis * t;
            Point3d localHitPos = hitPos - getPos();
            Point3d rotatedHitPos = rotatePoint3D(localHitPos, -getAxis().x, -getAxis().y, -getAxis().z);
            if (rotatedHitPos.x <= _length / 2.0 && rotatedHitPos.x >= -_length / 2.0 &&
                rotatedHitPos.y <= _width / 2.0 && rotatedHitPos.y >= -_width / 2.0) {
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
