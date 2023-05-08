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

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    bool changed = false;
    std::unique_ptr<Scene::IScene> scene = std::make_unique<Scene::Scene>();
    std::shared_ptr<Transformable::Camera::ICamera> camera = std::make_shared<Transformable::Camera::Camera>(Transformable::Point3d{-10, 10, 0}, Transformable::Point3d{0, 0, 0}, 200, 200, 90);
    std::shared_ptr<Material::IMaterial> material = std::make_shared<Material::FlatColor>(Display::Color{255, 0, 0});
    std::shared_ptr<Material::IMaterial> material2 = std::make_shared<Material::FlatColor>(Display::Color{0, 255, 0});
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{0, 0, 0}, 2.0f, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere2 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{0, 0, 5}, 2.0f, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere3 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{0, 4, 5}, 2.0f, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> sphere4 = std::make_shared<Transformable::Primitive::Sphere>(Transformable::Point3d{0, -4, 5}, 2.0f, material);
    std::shared_ptr<Transformable::Primitive::IPrimitive> plane = std::make_shared<Transformable::Primitive::Plane>(Transformable::Point3d{0, 0, -5}, 20.0f, 10.0f, Transformable::Point3d{0, 0, 0}, material2);
    std::shared_ptr<Transformable::Light::ILight> light = std::make_shared<Transformable::Light::Ambient>(Display::Color{255, 255, 255}, (float)0.4, Transformable::Point3d{100, 0, 100});

    scene->addCamera(camera);
    scene->addPrimitive(sphere);
    scene->addPrimitive(sphere2);
    scene->addPrimitive(sphere3);
    scene->addPrimitive(sphere4);
    scene->addPrimitive(plane);
    scene->addLight(light);
    scene->playScene("test");

    sf::RenderWindow window(sf::VideoMode(200, 200), "My window");
    sf::Texture texture;
    texture.loadFromFile("./screenshots/test.png");
    sf::Sprite sprite(texture);
    while (window.isOpen()) {
        changed = false;
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
                camera->moveForward(0.5f);
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                camera->moveForward(-0.5f);
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
                camera->moveRight(-0.5f);
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                camera->moveRight(0.5f);
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                camera->setPos(Transformable::Point3d{camera->getPos().x, camera->getPos().y, camera->getPos().z + 0.5f});
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) {
                camera->setPos(Transformable::Point3d{camera->getPos().x, camera->getPos().y, camera->getPos().z - 0.5f});
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
                camera->setAxis({camera->getAxis().x, camera->getAxis().y + 2.0f, camera->getAxis().z});
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
                camera->setAxis({camera->getAxis().x, camera->getAxis().y - 2.0f, camera->getAxis().z});
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
                camera->setAxis({camera->getAxis().x, camera->getAxis().y, camera->getAxis().z - 2.0f});
                changed = true;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
                camera->setAxis({camera->getAxis().x, camera->getAxis().y, camera->getAxis().z + 2.0f});
                changed = true;
            }
        }
        if (changed) {
            scene->playScene("test");
            window.clear(sf::Color::Black);
            texture.loadFromFile("./screenshots/test.png");
            sf::Sprite sprite(texture);
            window.draw(sprite);
            window.display();
        }
    }
    return 0;
}
