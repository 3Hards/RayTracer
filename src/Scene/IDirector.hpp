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
         * @return bool
        */
        virtual bool playScene() = 0;
    };
}
