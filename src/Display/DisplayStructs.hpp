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
            Color(int r, int g, int b) : _r(r), _g(g), _b(b)
            {
                cap(_r);
                cap(_g);
                cap(_b);
            }
            int _r;
            int _g;
            int _b;
        private:
            void cap(int &val)
            {
                if (val > 255) {
                    val = 255;
                } else if (val < 0) {
                    val = 0;
                }
            }
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
