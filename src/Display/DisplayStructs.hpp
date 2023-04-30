/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Display structs
*/

#pragma once

namespace Display {
    struct Color {
        public:
            int _r;
            int _g;
            int _b;
    };
    struct Point2i {
        public:
            int _x;
            int _y;
    };
    struct Pixel {
        public:
            Color _color;
            Point2i _pos;
    };
}
