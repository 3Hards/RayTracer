/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Cone
*/

#include "Cone.hpp"

Transformable::Primitive::Cone::Cone(Point3d pos, double height, double radius, Point3d Axis, std::shared_ptr<Material::IMaterial> material)
    : Transformable::Primitive::APrimitive(material, pos, Axis), _radius(radius), _height(height)
{
    double angleX = getAxis().x * M_PI / 180.0;
    double angleY = getAxis().y * M_PI / 180.0;
    double angleZ = getAxis().z * M_PI / 180.0;
    Point3d pointB = getPos();
    Point3d pointR = {getPos().x + _radius / 2.0, getPos().y, getPos().z};
    Point3d pointS = {getPos().x, getPos().y + _height / 2.0, getPos().z};
    Point3d rotatedPointB = rotatePoint3D(pointB, angleX, angleY, angleZ);
    Point3d rotatedPointR = rotatePoint3D(pointR, angleX, angleY, angleZ);
    Point3d rotatedPointS = rotatePoint3D(pointS, angleX, angleY, angleZ);
    Point3d vectorBR; 
    vectorBR = rotatedPointR - rotatedPointB;
    Point3d vectorBS;
    vectorBS = rotatedPointS - rotatedPointB;
}

namespace Transformable
{
    namespace Primitive
    {
        Point3d Cone::rotatePoint3D(const Point3d &point, double angleX, double angleY, double angleZ)
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
                computeZ};

            return res;
        }

        // Point3d Cone::rotatePoint3D(const Transformable::Point3d &point, double angleX, double angleY, double angleZ)
        // {
        //     double x = point.x;
        //     double y = point.y;
        //     double z = point.z;

        //     double cosX = std::cos(angleX);
        //     double sinX = std::sin(angleX);
        //     double cosY = std::cos(angleY);
        //     double sinY = std::sin(angleY);
        //     double cosZ = std::cos(angleZ);
        //     double sinZ = std::sin(angleZ);

        //     double newX = x * (cosY * cosZ) + y * (cosX * sinZ + sinX * sinY * cosZ) + z * (sinX * sinZ - cosX * sinY * cosZ);
        //     double newY = -x * (cosY * sinZ) + y * (cosX * cosZ - sinX * sinY * sinZ) + z * (sinX * cosZ + cosX * sinY * sinZ);
        //     double newZ = x * sinY + y * (-sinX * cosY) + z * (cosX * cosY);

        //     return {newX, newY, newZ};
        // }
    }
}

// Point3d Transformable::Primitive::Cone::rotatePoint3D(const Point3d& point, double angleX, double angleY, double angleZ)
// {
//     Point3d rotatedPoint = point;
//     rotatedPoint.x = point.x;
//     rotatedPoint.y = point.y * std::cos(angleX) - point.z * std::sin(angleX);
//     rotatedPoint.z = point.y * std::sin(angleX) + point.z * std::cos(angleX);
//     rotatedPoint.x = rotatedPoint.x * std::cos(angleY) + rotatedPoint.z * std::sin(angleY);
//     rotatedPoint.y = rotatedPoint.y;
//     rotatedPoint.z = -rotatedPoint.x * std::sin(angleY) + rotatedPoint.z * std::cos(angleY);
//     rotatedPoint.x = rotatedPoint.x * std::cos(angleZ) - rotatedPoint.y * std::sin(angleZ);
//     rotatedPoint.y = rotatedPoint.x * std::sin(angleZ) + rotatedPoint.y * std::cos(angleZ);
//     return rotatedPoint;
// }

bool Transformable::Primitive::Cone::checkHitBaseCircle(std::shared_ptr<Raytracer::IVector> vector)
{
    Point3d vectorPos = vector->getPos();
    Point3d vectorAxis = vector->getAxis();

    Point3d diskNormal = {0, 0, 1};
    Point3d diskCenter = {0, 0, _height};

    double dotProduct = vectorAxis.dot(diskNormal);
    if (dotProduct == 0)
    {
        return false;
    }
    double t = (diskCenter - vectorPos).dot(diskNormal) / dotProduct;
    if (t < 0)
    {
        return false;
    }
    Point3d hitPos = vectorPos + vectorAxis * t;
    bool canSeeTheBigCone = vectorAxis.dot(diskNormal) < 0;
    if (canSeeTheBigCone && hitPos.x * hitPos.x + hitPos.y * hitPos.y <= _radius * _radius)
    {
        _lastHittedVector = vector;
        vector->setPos(hitPos);
        return true;
    }
    return false;
}

bool Transformable::Primitive::Cone::checkHit(std::shared_ptr<Raytracer::IVector> vector)
{
    Transformable::Point3d vectorPos = vector->getPos();
    Transformable::Point3d vectorAxis = vector->getAxis();

    double a = vectorAxis.dot(vectorAxis) - (1 + (_radius * _radius) / (_height * _height)) * (vectorAxis.z * vectorAxis.z);
    Transformable::Point3d dist = vectorPos - getPos();
    double b = 2.0 * (vectorAxis.dot(dist) - (1 + (_radius * _radius) / (_height * _height)) * (vectorAxis.z * dist.z));
    double c = dist.dot(dist) - (1 + (_radius * _radius) / (_height * _height)) * (dist.z * dist.z);
    double discriminant = b * b - 4.00 * a * c;

    if (discriminant < 0)
    {
        return false;
    }
    double t1 = (-b - std::sqrt(discriminant)) / (2.0 * a);
    // double t2 = (-b + std::sqrt(discriminant)) / (2.0 * a);
    Point3d hitPos = vectorPos + vector->getAxis() * t1;
    if (hitPos.z >= getPos().z && hitPos.z <= getPos().z + _height)
    {
        if (checkHitBaseCircle(vector))
        {
            return true;
        }
        vector->setPos(hitPos);
        _lastHittedVector = vector;
        return true;
    }
    if (hitPos.z >= getPos().z && hitPos.z <= getPos().z + _height)
    {
        if (checkHitBaseCircle(vector))
        {
            return true;
        }
        vector->setPos(hitPos);
        _lastHittedVector = vector;
        return true;
    }
    if (checkHitBaseCircle(vector))
    {
        return true;
    }
    return false;
}

Transformable::Point3d Transformable::Primitive::Cone::getNormalVector()
{
    Point3d I = getPos() + Point3d{0, 0, _height};
    // Point3d P = getPos();
    Point3d A = getPos() + Point3d{_radius, 0, _height};
    Point3d normal = I - A;
    normal.normalize();
    return normal;
}
