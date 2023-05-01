/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Director
*/

#include "Director.hpp"
#include <libconfig.h++>
#include <iostream>
#include <string>

Scene::Director::Director(std::string pathFile)
{
    libconfig::Config cfg;
    try {
        cfg.readFile(pathFile);
    }
    catch(const libconfig::FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    }
    catch(const libconfig::ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
            << " - " << pex.getError() << std::endl;
    }
    
    const libconfig::Setting& root = cfg.getRoot();
    const libconfig::Setting& elements = root["elements"];
    const libconfig::Setting& list = elements["list"];
    
    // Builder::Builder(list);
}

Scene::Director::~Director()
{
}

void Scene::Director::playScene()
{
}
