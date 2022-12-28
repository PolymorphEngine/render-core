/*
** EPITECH PROJECT, 2020
** CameraComponentImpl.hpp
** File description:
** header for CameraComponentImpl.c
*/


#pragma once

#include <vector>
#include <functional>
#include "CameraComponent.hpp"

namespace polymorph::engine::render
{

    class CameraImpl : public ACameraComponent
    {
    //////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit CameraImpl(GameObject entity, std::shared_ptr<myxmlpp::Node> data)
            : ACameraComponent(data, entity){};

            void build() override;

            void saveAll() override;

            ~CameraImpl() override = default;
//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            void update() override;

            void start() override;

            bool isTargetingObject() override;

            engine::GameObject getTargetObject() override;

            void setTargetPosition(engine::Vector3 targetPosition) override;

            void setTargetObject(engine::GameObject object) override;

            void setUp(engine::Vector3 up) override;

            void setFov(float fov) override;

            void begin3dMode() override;

            void end3dMode() override;

//////////////////////--------------------------/////////////////////////

    };

}

