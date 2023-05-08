/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** 3DMatrix
*/

#include "ITransformable.hpp"

namespace Transformable {

    class Matrix3d {
    
        public:
            Matrix3d();

            Matrix3d rotateX(double angle);

            Matrix3d rotateY(double angle);

            Matrix3d rotateZ(double angle);

            Matrix3d operator*(const Matrix3d& other) const;

            double& operator()(int i, int j);

            const double& operator()(int i, int j) const;

            private:
                double data[3][3];

        };

    Point3d operator*(const Matrix3d& matrix, const Point3d& point);
}
