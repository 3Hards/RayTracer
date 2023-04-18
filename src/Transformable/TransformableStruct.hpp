/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Transformable structs
*/

#pragma once

namespace Transformable {

    enum class TransformableType {
        Light,
        Primitive,
        Camera
    };

    struct Point3f {
        public:
            float x;
            float y;
            float z;
    };
}