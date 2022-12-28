/*
** EPITECH PROJECT, 2022
** WindowModule.cpp
** File description:
** WindowModule.cpp
*/

#include <polymorph/engine/debug.hpp>
#include "../../include/modules/WindowModule.hpp"
#include <memory>


polymorph::engine::render::DisplayModule::DisplayModule(
        safe_ptr<VideoSettings> settings, std::string title, api::PluginManager &Plugins):
        _settings(settings), _title(std::move(title))
{
    _loadModule(Plugins);
    if (_c_window == nullptr || _c_drawer == nullptr)
        throw debug::PluginException("render-core", "Failed to load window symbols");
    _windowModule = std::unique_ptr<polymorph::graphical::IWindow>(_c_window(
            static_cast<int>(_settings->Resolution.x),
            static_cast<int>(_settings->Resolution.y),
            _title));
    _drawingModule = std::unique_ptr<polymorph::graphical::IDrawer>(_c_drawer());
    setFullscreen(_settings->Fullscreen);
    setTitle(_title);
    _actualResolution = _settings->Resolution;
}

polymorph::engine::render::DisplayModule::~DisplayModule()
{
    if (isOpen())
        close();
}

void polymorph::engine::render::DisplayModule::close()
{
    if (isOpen())
        _windowModule->close();
}

bool polymorph::engine::render::DisplayModule::isOpen()
{
    return _windowModule->isOpen();
}

bool polymorph::engine::render::DisplayModule::isFullscreen()
{
    return _windowModule->isFullscreen();
}

void polymorph::engine::render::DisplayModule::setFullscreen(bool fullscreen)
{
    return _windowModule->setFullscreen(fullscreen);
}

void polymorph::engine::render::DisplayModule::setTitle(const std::string &title)
{
    _windowModule->setTitle(title);
}

polymorph::engine::Vector2 polymorph::engine::render::DisplayModule::getResolution() const
{
    return _settings->Resolution;
}

void polymorph::engine::render::DisplayModule::clearWindow(polymorph::engine::Color color)
{
    _drawingModule->clear(color.r, color.g, color.b, color.a);
}

void polymorph::engine::render::DisplayModule::clearWindow()
{
    _drawingModule->clear(0, 0, 0, 255);
}

void polymorph::engine::render::DisplayModule::beginDrawing()
{
    _drawingModule->beginDrawing();
}

void polymorph::engine::render::DisplayModule::endDrawing()
{
    _drawingModule->endDrawing();
}

void polymorph::engine::render::DisplayModule::_loadModule(polymorph::engine::api::PluginManager &Plugins)
{
    if (_c_window)
        return;
    _c_window = Plugins.getSymbol<polymorph::graphical::Symbols::createWindowDEF>(polymorph::graphical::Symbols::createWindow);
    if (_c_drawer)
        return;
    _c_drawer = Plugins.getSymbol<polymorph::graphical::Symbols::createDrawerDEF>(polymorph::graphical::Symbols::createDrawer);
    
}

void polymorph::engine::render::DisplayModule::setLogLevel(int level)
{
    _windowModule->setLogLevel(level);
}

void polymorph::engine::render::DisplayModule::update()
{
    _windowModule->setFullscreen(_settings->Fullscreen);
    
    if (_actualResolution != _settings->Resolution) {
        _windowModule->close();
        _windowModule.reset();
        _windowModule = std::unique_ptr<polymorph::graphical::IWindow>(_c_window(
                static_cast<int>(_settings->Resolution.x),
                static_cast<int>(_settings->Resolution.y),
                _title));
        setFullscreen(_settings->Fullscreen);
        setTitle(_title);
        _actualResolution = _settings->Resolution;
    }
}
