/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IDirector
*/

#pragma once

namespace Scene {
    class IDirector {
        public:
            virtual bool playScene() = 0;
    };
}
