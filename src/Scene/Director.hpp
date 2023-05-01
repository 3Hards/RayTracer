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

#endif /* !DIRECTOR_HPP_ */
