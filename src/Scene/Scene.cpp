/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

#include <iostream>
#include <cmath>
#include "Scene.hpp"
#include "ILibGraphicHandler.hpp"
#include "ITransformable.hpp"
#include "LightCalculator.hpp"
#include "LibGraphicHandler.hpp"
#include "IVector.hpp"
#include "Vector.hpp"

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

namespace Scene {

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

    void Scene::handle_events(Display::LibGraphicHandler &libGraphicHandler)
    {
        std::vector<Display::Event> events = libGraphicHandler.getEvents();

        for (auto event : events) {

            if (event == Display::Event::KEYBORD_Z_PRESSED) {
                _cameras[0]->moveForward(5);
            }
            if (event == Display::Event::KEYBORD_S_PRESSED) {
                _cameras[0]->moveForward(-5);
            }
            if (event == Display::Event::KEYBORD_Q_PRESSED) {
                _cameras[0]->moveRight(-5);
            }
            if (event == Display::Event::KEYBORD_D_PRESSED) {
                _cameras[0]->moveRight(5);
            }
            if (event == Display::Event::KEYBORD_I_PRESSED) {
                _cameras[0]->rotateY(-5);
            }
            if (event == Display::Event::KEYBORD_K_PRESSED) {
                _cameras[0]->rotateY(5);
            }
            if (event == Display::Event::KEYBORD_J_PRESSED) {
                _cameras[0]->rotateZ(-5);
            }
            if (event == Display::Event::KEYBORD_L_PRESSED) {
                _cameras[0]->rotateZ(5);
            }

            if (event == Display::Event::KEYBORD_A_PRESSED) {
                _cameras[0]->rotateX(-5);
            }
            if (event == Display::Event::KEYBORD_E_PRESSED) {
                _cameras[0]->rotateX(5);
            }

            if (event == Display::Event::KEYBORD_SPACE_PRESSED) {
                _cameras[0]->moveUp(5);
            }
            if (event == Display::Event::KEYBORD_SHIFT_PRESSED) {
                _cameras[0]->moveUp(-5);
            }

            if (event == Display::Event::KEYBORD_R_PRESSED) {
                libGraphicHandler.exportImage();
            }

            if (event == Display::Event::KEYBORD_ESCAPE_PRESSED) {
                libGraphicHandler.closeWindow();
            }

            if (event == Display::Event::WINDOW_RESIZED) {
                std::pair<unsigned int, unsigned int> windowSize = libGraphicHandler.getWindowSize();
                _cameras[0]->setWidth(windowSize.first);
                _cameras[0]->setHeight(windowSize.second);
            }

        }
    }

    void Scene::computeVectors(std::shared_ptr<Raytracer::IVector> vector)
    {
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[0]->getWidth(), _cameras[0]->getHeight());
        libGraphicHandler.createWindow("Raytracer", _cameras[0]->getWidth(), _cameras[0]->getHeight());

        while (libGraphicHandler.isWindowOpen()) {
            for (unsigned int y = 0; y < _cameras[0]->getHeight(); y++) {
                for (unsigned int x = 0; x < _cameras[0]->getWidth(); x++) {
                    vector->setPos(_cameras[0]->getPos());
                    vector->setAxis(_cameras[0]->getRayAxis((int)x, (int)y));
                    Raytracer::LightCalculator calculator(vector, _lights[0]);
                    Display::Point2i pixelPos = {(int)x, (int)y};
                    libGraphicHandler.addPixelToBuffer(createPixel(calculator.computePixel(), pixelPos));
                }
            }
            handle_events(libGraphicHandler);
            libGraphicHandler.refreshWindow();
        }
    }

    void Scene::playScene(std::string const &filename)
    {
        _filename = filename;

        if (_lights.size() == 0 || _primitives.size() == 0 || _cameras.size() == 0) {
            return;
        }
        unsigned int camWidth = _cameras[0]->getWidth();
        unsigned int camHeight = _cameras[0]->getHeight();
        std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(_cameras[0]->getPos(), Transformable::Point3d{0, 0, 0});
        vector->setPrimitives(_primitives);
        computeVectors(vector);
    }

    Display::Pixel Scene::createPixel(Display::Color color, Display::Point2i position)
    {
        Display::Pixel pixel(color, position);
        return pixel;
    }
}
