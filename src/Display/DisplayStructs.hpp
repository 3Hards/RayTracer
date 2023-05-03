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
            Color(int r, int g, int b)
            {
                if (r > 255)
                    _r = 255;
                else if (r < 0)
                    _r = 0;
                else
                    _r = r;
                if (g > 255)
                    _g = 255;
                else if (g < 0)
                    _g = 0;
                else
                    _g = g;
                if (b > 255)
                    _b = 255;
                else if (b < 0)
                    _b = 0;
                else
                    _b = b;
            }
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
            Pixel(Color color, Point2i pos) : _color(color), _pos(pos)
            {}
            Color _color;
            Point2i _pos;
    };
}
