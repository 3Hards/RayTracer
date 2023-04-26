/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Transformable structs
*/

#pragma once

namespace Transformable {

    enum class TransformableType {
        LIGHT,
        PRIMITIVE,
        CAMERA,
        VECTOR
    };

    struct Point3f {
        public:
            double x;
            double y;
            double z;
    };
}