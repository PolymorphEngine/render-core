/*
** EPITECH PROJECT, 2022
** SerializableObjectFactory.cpp
** File description:
** SerializableObjectFactory.cpp
*/

#include "SerializableObjectFactory.hpp"
#include "modules/CameraModule.hpp"

polymorph::engine::api::SerializableObjectFactory::SerializableObjectFactory()
: ASerializableObjectFactory()
{
}

void polymorph::engine::api::SerializableObjectFactory::_registerEmptyBuildables(
        std::unordered_map<std::string, std::function<std::shared_ptr<ASerializableObject>(
                PluginManager&)>> &emptyBuildables)
{
    emptyBuildables.emplace("CameraModule", SerializableObjectFactory::makeEmpty<render::CameraModuleImpl>());
}

void polymorph::engine::api::SerializableObjectFactory::_registerCObjectBuildables(
        std::unordered_map <std::string, std::function<std::shared_ptr<ASerializableObject>(
                safe_ptr<AComponent>,
                std::shared_ptr<myxmlpp::Node>)>> &componentBuildables)
{
    componentBuildables.emplace("CameraModule", SerializableObjectFactory::makeCObject<render::CameraModuleImpl>());
}

void polymorph::engine::api::SerializableObjectFactory::_registerPObjectBuildables(
        std::unordered_map <std::string, std::function<std::shared_ptr<ASerializableObject>(
                safe_ptr<APluginConfig>,
                std::shared_ptr<myxmlpp::Node>)>> &configBuildables)
{
    configBuildables.emplace("CameraModule", SerializableObjectFactory::makePObject<render::CameraModuleImpl>());
}
