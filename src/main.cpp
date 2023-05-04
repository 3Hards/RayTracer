/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Ambient.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Director.hpp"
#include "FlatColor.hpp"
#include "Translation.hpp"

int main()
{
    std::cout << "Hello World!" << std::endl;
    std::unique_ptr<Scene::IScene> scene = std::make_unique<Scene::Scene>();
    std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3f{0, 0, 0}, Transformable::Point3f{0, 0, 1}, 500, 500, 90);
    std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 0, 0});
    std::shared_ptr<Material::IMaterial> material2 = std::make_shared<Material::FlatColor>(Display::Color{0, 0, 255});
    std::shared_ptr<Material::IMaterial> material3 = std::make_shared<Material::FlatColor>(Display::Color{0, 255, 0});
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3f{100, 0, 0}, 50, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere2 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3f{30, 35, 0}, 100, material2);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere3 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3f{50, 65, 0}, 100, material3);
    std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambiant>(Display::Color{255, 255, 255}, (float)0.5 , Transformable::Point3f{20, 20, 20});

    Scene::Director director(std::string("test"));
    director.playScene();

    return 0;
}