/*
** EPITECH PROJECT, 2022
** CameraModuleImpl.cpp
** File description:
** CameraModuleImpl.cpp
*/

#include <polymorph/engine/render-modules.hpp>
#include "PluginCore.hpp"
#include "modules/CameraModule.hpp"


polymorph::engine::render::CameraModuleImpl::CameraModuleImpl(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node)
: ACameraModule(component, node)
{
    _loadModule(component->Plugin);
    build();
    _camera = std::unique_ptr<polymorph::graphical::ICamera>(_c_camera());
    _camera->setUp(_up.x, _up.y, _up.z);
    _camera->setPosition(_position.x, _position.y, _position.z);
    _camera->setTarget(_target.x, _target.y, _target.z);
    _camera->setFOV(_fov);
}



polymorph::engine::render::CameraModuleImpl::CameraModuleImpl(
        polymorph::engine::safe_ptr<polymorph::engine::api::APluginConfig> config,
        std::shared_ptr<myxmlpp::Node> node)
        : ACameraModule(config, node)
{
    _loadModule(config->Plugin);
    build();
    _camera = std::unique_ptr<polymorph::graphical::ICamera>(_c_camera());
    _camera->setUp(_up.x, _up.y, _up.z);
    _camera->setPosition(_position.x, _position.y, _position.z);
    _camera->setTarget(_target.x, _target.y, _target.z);
    _camera->setFOV(_fov);
}


polymorph::engine::render::CameraModuleImpl::CameraModuleImpl(
        polymorph::engine::api::PluginManager &Plugins) : ACameraModule(Plugins)
{
    _loadModule(Plugins);
    _camera = std::unique_ptr<polymorph::graphical::ICamera>(_c_camera());

}


void polymorph::engine::render::CameraModuleImpl::build()
{
    _setProperty("_up", _up);
    _setProperty("_position", _position);
    _setProperty("_target", _target);
    _setProperty("_fov", _fov);
}

void polymorph::engine::render::CameraModuleImpl::saveAll()
{
    saveProperty("_up", _up);
    saveProperty("_position", _position);
    saveProperty("_target", _target);
    saveProperty("_fov", _fov);
}


void polymorph::engine::render::CameraModuleImpl::setTarget(polymorph::engine::Vector3 target)
{
    _target = target;
    _camera->setTarget(_target.x, _target.y, _target.z);
}

void polymorph::engine::render::CameraModuleImpl::setPosition(polymorph::engine::Vector3 pos)
{
    _position = pos;
    _camera->setPosition(_position.x, _position.y, _position.z);
}

void polymorph::engine::render::CameraModuleImpl::move(polymorph::engine::Vector3 pos)
{
    _position = pos;
    _camera->move(pos.x, pos.y, pos.z);
}

void polymorph::engine::render::CameraModuleImpl::setUp(polymorph::engine::Vector3 up)
{
    _up = up;
    _camera->setUp(up.x, up.y, up.z);
}

void polymorph::engine::render::CameraModuleImpl::setFOV(float fov)
{
    _fov = fov;
    _camera->setFOV(_fov);
}

void polymorph::engine::render::CameraModuleImpl::begin3DMode()
{
    _camera->begin3DMode();
}

void polymorph::engine::render::CameraModuleImpl::end3DMode()
{
    _camera->end3DMode();
}

float polymorph::engine::render::CameraModuleImpl::getFov() const
{
    return _fov;
}

polymorph::engine::Vector3 polymorph::engine::render::CameraModuleImpl::getUp() const
{
    return _up;
}

void polymorph::engine::render::CameraModuleImpl::_loadModule(polymorph::engine::api::PluginManager &Plugins)
{
    if (_c_camera)
        return;
    _c_camera = Plugins.getSymbol<polymorph::graphical::Symbols::createCameraDEF>(polymorph::graphical::Symbols::createCamera);
}




