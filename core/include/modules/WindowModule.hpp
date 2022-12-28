/*
** EPITECH PROJECT, 2020
** WindowModule.hpp
** File description:
** header for WindowModule.c
*/


#pragma once

#include <polymorph/engine/render-modules.hpp>
#include <polymorph/engine/types.hpp>
#include "../VideoSettings.hpp"

namespace polymorph::engine::render
{

    class DisplayModule
    {

////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////

        public:
            explicit DisplayModule(
                    safe_ptr<VideoSettings> settings,
                    std::string title, polymorph::engine::api::PluginManager &Plugins);

            ~DisplayModule();


//////////////////////--------------------------/////////////////////////



///////////////////////////// PROPERTIES ////////////////////////////////
        public:

        private:
            polymorph::graphical::Symbols::createWindowDEF _c_window = nullptr;

            polymorph::graphical::Symbols::createDrawerDEF _c_drawer = nullptr;

            const std::string &_title;
            std::unique_ptr<polymorph::graphical::IWindow> _windowModule;
            std::unique_ptr<polymorph::graphical::IDrawer> _drawingModule;
            safe_ptr<VideoSettings> _settings;
            Vector2 _actualResolution;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            // Window
            void close();

            bool isOpen();

            bool isFullscreen();

            void setFullscreen(bool fullscreen);

            void setTitle(const std::string &title);

            engine::Vector2 getResolution() const;

            void setLogLevel(int level);

            // Drawing
            void clearWindow(engine::Color color);

            void clearWindow();

            void beginDrawing();

            void endDrawing();
            
            void update();

        private:
            void _loadModule(polymorph::engine::api::PluginManager &Plugins);

//////////////////////--------------------------/////////////////////////

    };

}
