#include <iostream>
#include "Sphere.hpp"
#include "Vector.hpp"

int main() {
    std::cout << "Hello World!" << std::endl;
    Transformable::Primitive::Sphere sphere({0, 0, 0}, 1, Material::IMaterial());
    std::unique_ptr<Raytracer::IVector> IVector = std::make_unique<Raytracer::Vector>(Transformable::Point3f{0, 1.1, 0}, Transformable::Point3f{0, 0, 1});
    std::cout << "hit: " << std::get<0>(sphere.checkHit(IVector)) << std::endl;
    return 0;
}