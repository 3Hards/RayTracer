/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

#include <iostream>
#include <cmath>
#include <functional>
#include <unordered_map>
#include "Scene.hpp"
#include "ILibGraphicHandler.hpp"
#include "ITransformable.hpp"
#include "LibGraphicHandler.hpp"
#include "IVector.hpp"
#include "Vector.hpp"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace Scene {

    Scene::Scene() : _changeScene(false), _currentCamera(0) {}

    void Scene::addCamera(std::shared_ptr<Transformable::Camera::ICamera> camera)
    {
        _cameras.push_back(camera);
    }

    void Scene::addLight(std::shared_ptr<Transformable::Light::ILight> light)
    {
        _lights.push_back(light);
    }

    void Scene::addPrimitive(std::shared_ptr<Transformable::Primitive::IPrimitive> primitive)
    {
        _primitives.push_back(primitive);
    }

    void Scene::addTransformation(std::shared_ptr<Transformation::ITransformation> transformation)
    {
        _transformations.push_back(transformation);
    }

    const std::unordered_map<Display::Event, std::function<void(std::shared_ptr<Transformable::Camera::ICamera>&)>> _eventMappings = {
        { Display::Event::KEYBOARD_Z_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->moveForward(2); }},
        { Display::Event::KEYBOARD_S_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->moveForward(-2); }},
        { Display::Event::KEYBOARD_Q_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->moveRight(-2); }},
        { Display::Event::KEYBOARD_D_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->moveRight(2); }},
        { Display::Event::KEYBOARD_I_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->rotateY(-2); }},
        { Display::Event::KEYBOARD_K_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->rotateY(2); }},
        { Display::Event::KEYBOARD_J_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->rotateZ(-2); }},
        { Display::Event::KEYBOARD_L_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->rotateZ(2); }},
        { Display::Event::KEYBOARD_A_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->rotateX(-2); }},
        { Display::Event::KEYBOARD_E_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->rotateX(2); }},
        { Display::Event::KEYBOARD_SPACE_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->moveUp(2); }},
        { Display::Event::KEYBOARD_SHIFT_PRESSED, [](std::shared_ptr<Transformable::Camera::ICamera>& cam) { cam->moveUp(-2); }}
    };

    void Scene::switchCamera(Display::Event event)
    {
        size_t targetCamera = _currentCamera;
        targetCamera = static_cast<int>((int)event - (int)Display::Event::KEYBOARD_1_PRESSED);
        if (targetCamera < _cameras.size() && targetCamera != _currentCamera) {
            _currentCamera = targetCamera;
        }
    }

    void Scene::handle_events(Display::LibGraphicHandler &libGraphicHandler)
    {
        std::vector<Display::Event> events = libGraphicHandler.getEvents();
        
        for (auto event : events) {
            if (_eventMappings.find(event) != _eventMappings.end()) {
                _eventMappings.at(event)(_cameras[_currentCamera]);
            }
        }
        for (auto event : events) {
            if (event == Display::Event::KEYBOARD_R_PRESSED) {
                libGraphicHandler.exportImage();
            }
            if (event == Display::Event::KEYBOARD_ESCAPE_PRESSED) {
                libGraphicHandler.closeWindow();
            }
            if (event == Display::Event::WINDOW_RESIZED) {
                std::pair<unsigned int, unsigned int> windowSize = libGraphicHandler.getWindowSize();
                _cameras[_currentCamera]->setWidth(windowSize.first);
                _cameras[_currentCamera]->setHeight(windowSize.second);
            }
            if (event == Display::Event::KEYBOARD_RIGHT_PRESSED) {
                _changeScene = true;
            }
            if (event >= Display::Event::KEYBOARD_1_PRESSED && event <= Display::Event::KEYBOARD_9_PRESSED) {
                switchCamera(event);
            }
        }
    }

    void Scene::computeVectors(std::shared_ptr<Raytracer::IVector> vector)
    {
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[_currentCamera]->getWidth(), _cameras[_currentCamera]->getHeight());
        libGraphicHandler.createWindow("Raytracer", _cameras[_currentCamera]->getWidth(), _cameras[_currentCamera]->getHeight());

        while (libGraphicHandler.isWindowOpen() && _changeScene == false) {
            for (unsigned int y = 0; y < _cameras[_currentCamera]->getHeight(); y++) {
                for (unsigned int x = 0; x < _cameras[_currentCamera]->getWidth(); x++) {
                    vector->setPos(_cameras[_currentCamera]->getPos());
                    vector->setAxis(_cameras[_currentCamera]->getRayAxis((int)x, (int)y));
                    Display::Point2i pixelPos = {(int)x, (int)y};
                    libGraphicHandler.addPixelToBuffer(createPixel(vector->computeColor(_lights), pixelPos));
                }
            }
            handle_events(libGraphicHandler);
            libGraphicHandler.refreshWindow();
        }
    }

    bool Scene::playScene(std::string const &filename)
    {
        _filename = filename;

        if (_lights.size() == 0 || _primitives.size() == 0 || _cameras.size() == 0) {
            return true;
        }
        std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(_cameras[_currentCamera]->getPos(), Transformable::Point3d{0, 0, 0});
        vector->setPrimitives(_primitives);
        computeVectors(vector);
        return _changeScene;
    }

    Display::Pixel Scene::createPixel(Display::Color color, Display::Point2i position)
    {
        Display::Pixel pixel(color, position);
        return pixel;
    }
}
