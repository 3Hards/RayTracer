/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightCalculator header
*/

#include "ILightCalculator.hpp"
#include "IVector.hpp"
#include "ILight.hpp"

namespace Raytracer {
    class LightCalculator : public ILightCalculator {
        public:
            LightCalculator(std::shared_ptr<IVector>, std::shared_ptr<Transformable::Light::ILight>);
            Display::Color computePixel() final;
        private:
            std::shared_ptr<IVector> _vector;
            std::shared_ptr<Transformable::Light::ILight> _light;
    };
}
