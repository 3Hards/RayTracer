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
#include "Builder.hpp"

Scene::Director::Director(std::string pathFile)
{
    libconfig::Config cfg;
    try {
        cfg.readFile(pathFile);
        const libconfig::Setting& root = cfg.getRoot();
        const libconfig::Setting& elements = root["elements"];
        libconfig::Setting& list = elements["list"];
        Builder builder(list);
    }
    catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    }
    catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << std::endl;
    }
}

Scene::Director::~Director()
{
}

void Scene::Director::playScene()
{
    std::cout << "play scene" << std::endl;
}
