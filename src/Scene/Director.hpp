/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Director
*/

#ifndef DIRECTOR_HPP_
#define DIRECTOR_HPP_

#include <iostream>
#include "IDirector.hpp"

namespace Scene {
    class Director : public IDirector {
        public:
            Director(std::string pathFile);
            ~Director();
            void playScene();


        protected:
        private:
    };
}

struct Element {
    std::string type;
    int x, y, z;
    double r, g, b;
    double brightness;
    int width, height;
    int axis_x, axis_y, axis_z;
    std::string transType;
    int transX, transY, transZ;
};

#endif /* !DIRECTOR_HPP_ */
