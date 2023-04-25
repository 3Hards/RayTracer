/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include <iostream>
#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "FlatColor.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::unique_ptr<Scene::IScene> scene = std::make_unique<Scene::Scene>();
    std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3f{0, 0, -20}, Transformable::Point3f{0, 0, 1}, 10, 10, 90);
    std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 0, 0});
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3f{0, 0, 0}, 5, material);
    //scene->addCamera(camera);
    //scene->addPrimitive(sphere);
    //scene->addLight(light);
    //scene->playScene("test");
    return 0;
}
