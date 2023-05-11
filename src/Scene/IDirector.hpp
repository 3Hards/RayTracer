/*
** EPITECH PROJECT, 2023
** RayTracer
** File description:
** IDirector
*/

#pragma once

namespace Scene
{
    /**
     * @brief Interface for the director
    */
    class IDirector
    {
    public:
        /**
         * @brief Play the scene
         * @return
        */
        virtual void playScene() = 0;

    };
}
