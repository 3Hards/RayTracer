/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "Transformable/Camera/Camera.hpp"

#include <iostream>
#include "Vector.hpp"

int main()
{
    //std::cout << "Hello World!" << std::endl;
    //Transformable::Camera::Camera camera({0, 0, 0}, {42, 0, 42}, 1920, 1080, 90);
    //return 0;
    std::vector<std::shared_ptr<Transformable::Primitive::IPrimitive>> list;
    Raytracer::Vector vector({0, 0, 0}, {0, 0, 1});
    std::unique_ptr<Raytracer::Vector> vec = std::make_unique<Raytracer::Vector>(vector);
    Transformable::Light::ILight light;

    vector.setPrimitives(list);
    Transformable::Point3f pos = vector.getPos();
    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;
    vector.run(light);
    pos = vector.getPos();
    std::cout << pos.x << " " << pos.y << " " << pos.z << std::endl;

    std::unique_ptr<Raytracer::IVector> vecI = std::make_unique<Raytracer::Vector>(vector);
    vecI->getAxis();

    std::unique_ptr<Raytracer::IVector> veccctor = nullptr;
    veccctor = std::make_unique<Raytracer::Vector>(vector);

    veccctor->getAxis();
}
