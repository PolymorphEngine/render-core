/*
** EPITECH PROJECT, 2020
** VideoSettings.cpp
** File description:
** header for VideoSettings.c
*/

#include "VideoSettings.hpp"

namespace polymorph::engine::render
{
    VideoSettings::VideoSettings(Engine &engine, std::string filePath)
            : APluginConfig(engine, filePath)
    {

    }
    void VideoSettings::build()
    {
        _setProperty("DefaultMode", DefaultMode);
        _setProperty("Resolution", Resolution);
        _setProperty("Fullscreen", Fullscreen);
        _setProperty("MaxFPS", MaxFPS);
        _setProperty("UncappedFPS", UncappedFPS);
        _setProperty("BitsPerPixel", BitsPerPixel);
        _setProperty("AntiAliasing", AntiAliasing);
        _setProperty("AntiAliasingLevel", AntiAliasingLevel);
        _setProperty("Resizable", Resizable);
        _setProperty("VSync", VSync);
        
    }

    void VideoSettings::saveAll()
    {
        saveProperty("DefaultMode", DefaultMode);
        saveProperty("Resolution", Resolution);
        saveProperty("Fullscreen", Fullscreen);
        saveProperty("MaxFPS", MaxFPS);
        saveProperty("UncappedFPS", UncappedFPS);
        saveProperty("BitsPerPixel", BitsPerPixel);
        saveProperty("AntiAliasing", AntiAliasing);
        saveProperty("AntiAliasingLevel", AntiAliasingLevel);
        saveProperty("Resizable", Resizable);
        saveProperty("VSync", VSync);
    }


} // render_core