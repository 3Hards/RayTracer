/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** 3DMatrix
*/

/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** 3DMatrix
*/

#include "ITransformable.hpp"
#include "3DMatrix.hpp"

namespace Transformable {

    Matrix3d::Matrix3d() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                data[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
    }

    Matrix3d Matrix3d::rotateX(double angle) {
        Matrix3d rotationMatrix;
        rotationMatrix.data[1][1] = std::cos(angle);
        rotationMatrix.data[1][2] = -std::sin(angle);
        rotationMatrix.data[2][1] = std::sin(angle);
        rotationMatrix.data[2][2] = std::cos(angle);
        return (*this) * rotationMatrix;
    }

    Matrix3d Matrix3d::rotateY(double angle) {
        Matrix3d rotationMatrix;
        rotationMatrix.data[0][0] = std::cos(angle);
        rotationMatrix.data[0][2] = std::sin(angle);
        rotationMatrix.data[2][0] = -std::sin(angle);
        rotationMatrix.data[2][2] = std::cos(angle);
        return (*this) * rotationMatrix;
    }

    Matrix3d Matrix3d::rotateZ(double angle) {
        Matrix3d rotationMatrix;
        rotationMatrix.data[0][0] = std::cos(angle);
        rotationMatrix.data[0][1] = -std::sin(angle);
        rotationMatrix.data[1][0] = std::sin(angle);
        rotationMatrix.data[1][1] = std::cos(angle);
        return (*this) * rotationMatrix;
    }

    Matrix3d Matrix3d::operator*(const Matrix3d& other) const {
        Matrix3d result;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result.data[i][j] = 0.0;
                for (int k = 0; k < 3; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    double& Matrix3d::operator()(int i, int j) {
        return data[i][j];
    }

    const double& Matrix3d::operator()(int i, int j) const {
        return data[i][j];
    }

    Point3d operator*(const Matrix3d& matrix, const Point3d& point) {
        Point3d result;
        result.x = matrix(0, 0) * point.x + matrix(0, 1) * point.y + matrix(0, 2) * point.z;
        result.y = matrix(1, 0) * point.x + matrix(1, 1) * point.y + matrix(1, 2) * point.z;
        result.z = matrix(2, 0) * point.x + matrix(2, 1) * point.y + matrix(2, 2) * point.z;
        return result;
    }
}
