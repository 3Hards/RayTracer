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
            bool playScene() final;
        private:
            std::shared_ptr<IBuilder> _builder;
            std::string _pathFile;
    };
}
