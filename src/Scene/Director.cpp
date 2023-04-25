/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Director
*/


#include "Director.hpp"
#include <libconfig.h++>

using namespace libconfig;

Scene::Director::Director(std::string pathFile)
{
    Config cfg;

    try {
        cfg.readFile("test.cfg");
    }
    catch(const FileIOException &fioex) {
        std::cerr << "I/O error while reading file." << std::endl;
    }
    catch(const ParseException &pex) {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
        << " - " << pex.getError() << std::endl;
    }

    const Setting &element = cfg.lookup("element");
    const Setting &list = element.lookup("list");

    int len = list.getLength();

    for(int i = 0; i < len; i++) {
        const Setting& element = list[i];
        const std::string& type = element.lookup("type");
        int x = element.lookup("x");
        int y = element.lookup("y");
        int z = element.lookup("z");
        int r = element.lookup("r");

        const Setting& color = element.lookup("color");
        int red = color.lookup("r");
        int green = color.lookup("g");
        int blue = color.lookup("b");

        std::cout << "Element " << i << ":" << std::endl;
        std::cout << "Type: " << type << std::endl;
        std::cout << "Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
        std::cout << "Radius: " << r << std::endl;
        std::cout << "Color: (" << red << ", " << green << ", " << blue << ")" << std::endl;
    }
}

Scene::Director::~Director()
{
}
