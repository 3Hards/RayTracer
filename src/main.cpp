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
    std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3d{0, 0, 0}, Transformable::Point3d{0, 0, 1}, 150, 150, 90);
    std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 0, 0});
    std::shared_ptr<Transformable::Primitive::IPrimitive> plane = std::make_shared<Transformable::Primitive::Plane>(Transformable::Point3d{100, 0, 0}, 25, 40, material);
    std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambient>(Display::Color{255, 255, 255}, (float)0.5 , Transformable::Point3d{0, 0, -5});

    scene->addCamera(camera);
    scene->addPrimitive(plane);
    scene->addLight(light);
    scene->playScene("test");
    return 0;
}
