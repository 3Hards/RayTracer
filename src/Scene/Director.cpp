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
    
    int count = list.getLength();
    for(int i = 0; i < count; ++i)
    {
        const libconfig::Setting &item = list[i];
        const std::string &type = item["type"];
        std::cout << "Type: " << type << std::endl;
        
        // create setting for each type of object
        if(type == "Sphere")
        {
            int x, y, z, r;
            const libconfig::Setting& color = item["color"];
            int cr, cg, cb;
            color.lookupValue("r", cr);
            color.lookupValue("g", cg);
            color.lookupValue("b", cb);
            item.lookupValue("x", x);
            item.lookupValue("y", y);
            item.lookupValue("z", z);
            item.lookupValue("r", r);
            std::cout << "Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
            std::cout << "Radius: " << r << std::endl;
            std::cout << "Color: (" << cr << ", " << cg << ", " << cb << ")" << std::endl;
        }
        else if(type == "Ambiant")
        {
            int x, y, z;
            double brightness;
            item.lookupValue("x", x);
            item.lookupValue("y", y);
            item.lookupValue("z", z);
            item.lookupValue("brightness", brightness);
            std::cout << "Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
            std::cout << "Brightness: " << brightness << std::endl;
        }
        else if(type == "Camera")
        {
            int x, y, z;
            int fov;
            const libconfig::Setting &axis = item["axis"];
            int ax, ay, az;
            const libconfig::Setting &res = item["resolution"];
            int rx, ry;
            const libconfig::Setting &trans = item["transformation"];
            std::string transType;
            int tx, ty, tz;
            item.lookupValue("x", x);
            item.lookupValue("y", y);
            item.lookupValue("z", z);
            item.lookupValue("fov", fov);
            axis.lookupValue("x", ax);
            axis.lookupValue("y", ay);
            axis.lookupValue("z", az);
            res.lookupValue("x", rx);
            res.lookupValue("y", ry);
            trans.lookupValue("type", transType);
            trans.lookupValue("x", tx);
            trans.lookupValue("y", ty);
            trans.lookupValue("z", tz);
            std::cout << "Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
            std::cout << "Axis: (" << ax << ", " << ay << ", " << az << ")" << std::endl;
            std::cout << "Field of view: " << fov << std::endl;
            std::cout << "Resolution: (" << rx << ", " << ry << ")" << std::endl;
            std::cout << "Transformation: " << transType << std::endl;
            std::cout << "Translation: (" << tx << ", " << ty << ", " << tz << ")" << std::endl;
        }
        else {
            std::cout << "Unknown type." << std::endl;
        }
    }
}

            


// Scene::Director::Director(std::string pathFile)
// {
//     libconfig::Config cfg;

//     try {
//         cfg.readFile(pathFile.c_str());
//     }
//     catch(const libconfig::FileIOException &fioex) {
//         std::cerr << "I/O error while reading file." << std::endl;
//     }
//     catch(const libconfig::ParseException &pex) {
//         std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
//         << " - " << pex.getError() << std::endl;
//     }

//     const libconfig::Setting &elements = cfg.lookup("elements");
//     const libconfig::Setting &list = elements.lookup("list");

//     int len = list.getLength();

//     for(int i = 0; i < len; i++) {
//         const libconfig::Setting& element = list[i];
//         const std::string& type = element.lookup("type");
//         int x = element.lookup("x");
//         int y = element.lookup("y");
//         int z = element.lookup("z");
//         int r = element.lookup("r");

//         const libconfig::Setting& color = element.lookup("color");
//         int red = color.lookup("r");
//         int green = color.lookup("g");
//         int blue = color.lookup("b");

//         std::cout << "Element " << i << ":" << std::endl;
//         std::cout << "Type: " << type << std::endl;
//         std::cout << "Position: (" << x << ", " << y << ", " << z << ")" << std::endl;
//         std::cout << "Radius: " << r << std::endl;
//         std::cout << "Color: (" << red << ", " << green << ", " << blue << ")" << std::endl;
//     }
// }

Scene::Director::~Director()
{
}

void Scene::Director::playScene()
{
}
