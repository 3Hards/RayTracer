/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Scene
*/

#include "Scene.hpp"
#include "ITransformable.hpp"
#include "LightCalculator.hpp"
#include "LibGraphicHandler.hpp"
#include "IVector.hpp"
#include "Vector.hpp"

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

    void Scene::computeVectors(unsigned int camWidth, unsigned int camHeight, Transformable::Point3d camPos, std::vector<Transformable::Point3d> axis)
    {
        unsigned int i = 0;
        std::shared_ptr<Raytracer::IVector> vector = std::make_shared<Raytracer::Vector>(camPos, axis[0]);
        vector->setPrimitives(_primitives);
        Display::LibGraphicHandler libGraphicHandler(_filename, _cameras[0]->getWidth(), _cameras[0]->getHeight());

        for (unsigned int y = 0; y < camHeight; y++) {
            for (unsigned int x = 0; x < camWidth && i <= axis.size(); x++) {
                Transformable::Point3d pos = {camPos.x + x, camPos.y + y, camPos.z};
                Display::Point2i pixelPos = {(int)x, (int)y};
                vector->setPos(pos);
                vector->setAxis(axis[i]);
                Raytracer::LightCalculator calculator(vector, _lights[0]);
                libGraphicHandler.addPixelToImage(createPixel(calculator.computePixel(), pixelPos));
                i++;
            }
        }
        libGraphicHandler.exportImage();
    }

    //camres = 1920 1080
    //camFov = 90
    //camPos = -110 0 160
    //camDirection = 0 -20 0

    std::vector<Transformable::Point3d> computeAxis()
{
    double camres_x = 1920;
    double camres_y = 1080;
    double camFov = 80;
    Transformable::Point3d camPos = {-110, 0, 110};
    Transformable::Point3d camDirection = {0, -20, 0};

    std::vector<Transformable::Point3d> axis;

    double f = (camres_y / 2.0) / tan(camFov / 2.0);

    double cx = cos(camDirection.x), cy = cos(camDirection.y), cz = cos(camDirection.z);
    double sx = sin(camDirection.x), sy = sin(camDirection.y), sz = sin(camDirection.z);

    double tx = -camPos.x, ty = -camPos.y, tz = -camPos.z;

    double m11 = cy * cz, m12 = cy * sz, m13 = 0.0;
    double m21 = sx * sy * cz - cx * sz, m22 = sx * sy * sz + cx * cz, m23 = sx * cy;
    double m31 = cx * sy * cz + sx * sz, m32 = cx * sy * sz - sx * cz, m33 = cx * cy;
    double m41 = tx * m11 + ty * m21 + tz * m31;
    double m42 = tx * m12 + ty * m22 + tz * m32;
    double m43 = tx * m13 + ty * m23 + tz * m33;

    for (int y = 0; y < camres_y; ++y)
    {
        for (int x = 0; x < camres_x; ++x)
        {
            double nx = (x - camres_y/2.0) / f;
            double ny = (y - camres_y/2.0) / f;
            double nz = 1.0;

            double wx = nx * m11 + ny * m21 + nz * m31 + m41;
            double wy = nx * m12 + ny * m22 + nz * m32 + m42;
            double wz = nx * m13 + ny * m23 + nz * m33 + m43;

            double dx = wx - camPos.x;
            double dy = wy - camPos.y;
            double dz = wz - camPos.z;
            double norm = sqrt(dx*dx + dy*dy + dz*dz);

            Transformable::Point3d direction = {0, 0, 0};
            direction.x = dx / norm;
            direction.y = dy / norm;
            direction.z = dz / norm;

            axis.push_back(direction);
        }
    }
    return axis;
}

    void Scene::playScene(std::string const &filename)
    {
        _filename = filename;
        std::vector<Transformable::Point3d> axis;

        if (_lights.size() == 0 || _primitives.size() == 0 || _cameras.size() == 0) {
            return;
        }
        axis = computeAxis();
        if (axis.size() == 0) {
            return;
        }
        unsigned int camWidth = _cameras[0]->getWidth();
        unsigned int camHeight = _cameras[0]->getHeight();
        Transformable::Point3d camPos = _cameras[0]->getPos();
        computeVectors(camWidth, camHeight, camPos, axis);
    }

    Display::Pixel Scene::createPixel(Display::Color color, Display::Point2i position)
    {
        Display::Pixel pixel;

        pixel._color = color;
        pixel._pos._x = position._x;
        pixel._pos._y = position._y;
        return pixel;
    }
}
