/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** Director
*/

#include <iostream>
#include "IDirector.hpp"
#include "Builder.hpp"
#include "IBuilder.hpp"

#pragma once

namespace Scene {
    class Director : public IDirector {
        public:
            Director(std::string pathFile);
            ~Director();
            void playScene();
        private:
            std::shared_ptr<IBuilder> _builder;
            std::string _pathFile;
    };
}
