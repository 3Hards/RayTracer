/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** main
*/

#include "Vector.hpp"
#include "Camera.hpp"
#include "Plane.hpp"
#include "FlatColor.hpp"
#include "Translation.hpp"
#include "Rotation.hpp"
#include "Director.hpp"
#include "Cone.hpp"
#include "Vector.hpp"
#include "Camera.hpp"
#include "Scene.hpp"
#include "Ambient.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Translation.hpp"

int main()
{
    std::unique_ptr<Scene::IScene> scene = std::make_unique<Scene::Scene>();
    std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3d{0, 0, 0}, Transformable::Point3d{0, 0, 0}, 200, 200, 90);
    std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 0, 0});
    std::shared_ptr<Material::IMaterial> material2 = std::make_shared<Material::FlatColor>(Display::Color{255, 255, 0});
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{2, 0, 0}, 40, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> cone = std::make_shared<Transformable::Primitive::Cone>(Transformable::Point3d{0, 0, 0}, 40, 40, 40, material);
    std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambient>(Display::Color{255, 255, 255}, (float)0.4, Transformable::Point3d{125, 300, 600});

    scene->addCamera(camera);
    scene->addPrimitive(sphere);
    scene->addPrimitive(cone);
    scene->addLight(light);
    
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere2 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{0, 0, 0}, 60, material2);
    scene->addPrimitive(sphere2);
    
    scene->playScene("test");
    return 0;
}



// int main()
// {

//     Scene::Director director("Config/test.cfg");
//     director.playScene();
//     return 0;
// }
