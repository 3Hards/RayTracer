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
#include "FlatColor.hpp"
#include "Translation.hpp"

int main()
{
    std::unique_ptr<Scene::IScene> scene = std::make_unique<Scene::Scene>();
    std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3d{-160.0, 0, 160}, Transformable::Point3d{0, 0, 0}, 1920, 1080, 90);
    std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 0, 0});
    std::shared_ptr<Material::IMaterial> material2 = std::make_shared<Material::FlatColor>(Display::Color{0, 255, 0});
    std::shared_ptr<Material::IMaterial> material3 = std::make_shared<Material::FlatColor>(Display::Color{0, 0, 255});
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{300.0, 300, 110}, 100, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere2 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{155.0, 100, 110}, 30, material2);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere3 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{355.0, 100, 10}, 30, material3);
    std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambient>(Display::Color{255, 255, 255}, (float)0.4, Transformable::Point3d{-200, 0, 0});

    scene->addCamera(camera);
    scene->addPrimitive(sphere);
    scene->addPrimitive(sphere2);
    scene->addPrimitive(sphere3);
    scene->addLight(light);
    scene->playScene("test");
    return 0;
}
