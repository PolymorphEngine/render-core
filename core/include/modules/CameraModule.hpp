/*
** EPITECH PROJECT, 2020
** CameraModule.hpp
** File description:
** header for CameraModule.c
*/


#pragma once

#include <polymorph/engine/render-modules.hpp>
#include <polymorph/engine/core.hpp>
#include <polymorph/engine/api.hpp>
#include <polymorph/engine/config.hpp>

namespace polymorph::engine::render
{
    
    class ACameraModule : public api::AConfigurableSerializableObject
    {
        public:
            ACameraModule (safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(component, node){};
            
            ACameraModule (safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node)
            : AConfigurableSerializableObject(config, node){};
            
            explicit ACameraModule(api::PluginManager &pluginManager)
            : AConfigurableSerializableObject(pluginManager){};

            ~ACameraModule() override = default;

///////////////////////////// PROPERTIES ////////////////////////////////
        public:


        protected:
            polymorph::graphical::Symbols::createCameraDEF _c_camera = nullptr;

            std::unique_ptr<polymorph::graphical::ICamera> _camera;
            float _fov = 90;
            engine::Vector3 _up;
            engine::Vector3 _position;
            engine::Vector3 _target;


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual void setTarget(engine::Vector3 target) = 0;

            virtual void setPosition(engine::Vector3 pos) = 0;

            virtual void move(engine::Vector3 pos) = 0;

            virtual engine::Vector3 getUp() const = 0;

            virtual void setUp(engine::Vector3 up) = 0;

            virtual float getFov() const = 0;

            virtual void setFOV(float fov) = 0;

            virtual void begin3DMode() = 0;

            virtual void end3DMode() = 0;
//////////////////////--------------------------/////////////////////////

    };
    using CameraModule = std::shared_ptr<ACameraModule>;

    class CameraModuleImpl : public ACameraModule
    {
        public:
            CameraModuleImpl(safe_ptr<AComponent> component, std::shared_ptr<myxmlpp::Node> node);
            
            CameraModuleImpl(safe_ptr<api::APluginConfig> config, std::shared_ptr<myxmlpp::Node> node);
            
            explicit CameraModuleImpl(api::PluginManager &pluginManager);

            ~CameraModuleImpl() override = default;


/////////////////////////////// METHODS /////////////////////////////////
        public:
            void setTarget(engine::Vector3 target) final;

            void setPosition(engine::Vector3 pos) final;

            void move(engine::Vector3 pos) final;

            engine::Vector3 getUp() const final;

            void setUp(engine::Vector3 up) final;

            float getFov() const final;

            void setFOV(float fov) final;

            void begin3DMode() final;

            void end3DMode() final;

            void build() override;

            void saveAll() override;

        private:
            void _loadModule(polymorph::engine::api::PluginManager &Plugins);


//////////////////////--------------------------/////////////////////////

    };
}


