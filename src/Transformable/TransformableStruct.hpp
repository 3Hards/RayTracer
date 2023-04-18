/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Transformable structs
*/

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