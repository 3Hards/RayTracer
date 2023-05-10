/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** FlatColor header
*/

#include "AMaterial.hpp"

namespace Material {
    class FlatColor : public AMaterial {
        public:
            FlatColor(Display::Color);
    };
}
