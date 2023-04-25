/*
** EPITECH PROJECT, 2023
** _rayTracer
** File description:
** FlatColor header
*/

#include "IMaterial.hpp"

namespace Material {
    class FlatColor : public IMaterial {
        public:
            FlatColor(Display::Color);
            Display::Color getColor(std::unique_ptr<Raytracer::IVector>&) final;
        private:
            Display::Color _color;
    };
}
