/*
** EPITECH PROJECT, 2020
** VideoSettings.hpp
** File description:
** header for VideoSettings.c
*/


#pragma once
#include "polymorph/engine/api.hpp"
#include "polymorph/engine/core.hpp"
#include "polymorph/engine/types.hpp"

namespace polymorph::engine::render
{
    class VideoSettings : public api::APluginConfig
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            VideoSettings(Engine &engine, std::string filePath);


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            Vector2 Resolution;
            bool Fullscreen = false;
            bool VSync = false;
            bool AntiAliasing = false;
            int AntiAliasingLevel = 0;
            bool Resizable = false;
            bool DefaultMode = true;
            int BitsPerPixel = 64;
            int MaxFPS = 30;
            bool UncappedFPS = false;
            


        private:

//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void build() override;

            void saveAll() override;

        private:

//////////////////////--------------------------/////////////////////////

    };

} // render_core
