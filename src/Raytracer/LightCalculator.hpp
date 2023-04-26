/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** LightCalculator header
*/

#include "ILibGraphicHandler.hpp"
#include "IVector.hpp"
#include "ILight.hpp"

namespace Raytracer {
    class LightCalculator : public ILightCalculator {
        public:
            LightCalculator(std::shared_ptr<IVector>, std::shared_ptr<Transformable::Light::ILight>);
            Display::Color computePixel() final;
        private:
            std::unique_ptr<IVector> getNewVector(Transformable::Point3f hitPos);
            std::shared_ptr<IVector> _vector;
            std::shared_ptr<Transformable::Light::ILight> _light;
    }
}
