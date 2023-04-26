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
            double computeScalarProduct(Transformable::Point3f fst, Transformable::Point3f scd);
            Display::Color compute();
            void redirectVector();

            Transformable::Point3f _incident;
            std::shared_ptr<IVector> _vector;
            std::shared_ptr<Transformable::Light::ILight> _light;
    }
}
