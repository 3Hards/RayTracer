/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Director
*/

#include <libconfig.h++>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Director.hpp"

Scene::Director::Director(std::string pathFile)
{
    libconfig::Config cfg;
    _pathFile = pathFile;
    cfg.readFile(pathFile.c_str());
    const libconfig::Setting& root = cfg.getRoot();
    const libconfig::Setting& elements = root["elements"];
    libconfig::Setting& list = elements["list"];
    _builder = std::make_shared<Builder>(list);

}

Scene::Director::~Director()
{
}

void Scene::Director::playScene()
{
    std::cout << "play scene" << std::endl;
    std::string _path = _pathFile.substr(_pathFile.find_last_of("/") + 1);
    _path = _path.substr(0, _path.find_last_of("."));
    std::cout << _path << std::endl;
    _builder->getScene()->playScene(_path);
}