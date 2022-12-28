/*
** EPITECH PROJECT, 2020
** CameraComponent.hpp
** File description:
** header for CameraComponent.c
*/


#pragma once

#include <vector>
#include <functional>
#include <polymorph/engine/core.hpp>
#include <polymorph/engine/types.hpp>
#include "modules/CameraModule.hpp"

namespace polymorph::engine::render
{

    class ACameraComponent;
    using Camera = safe_ptr<ACameraComponent>;

    class ACameraComponent : public polymorph::engine::AComponent
    {

//////////////////////// CONSTRUCTORS/DESTRUCTORS /////////////////////////
        public:
            explicit ACameraComponent(std::shared_ptr<myxmlpp::Node> data, GameObject entity)
            : AComponent(data, entity){};
            ~ACameraComponent() override = default;
///////////////////////////// PROPERTIES ////////////////////////////////
        public:
            enum CameraTargetType : int
            {
                Point,
                Object,
            };
            CameraTargetType TargetType = Object;
            engine::GameObject ObjectTarget;
            engine::Vector3 PointTarget;

            CameraModule camera;

        private:


//////////////////////--------------------------/////////////////////////



/////////////////////////////// METHODS /////////////////////////////////
        public:
            virtual bool isTargetingObject() = 0;

            virtual engine::GameObject getTargetObject() = 0;

            virtual void setTargetPosition(engine::Vector3 targetPosition) = 0;

            virtual void setTargetObject(engine::GameObject object) = 0;

            virtual void setUp(engine::Vector3 up) = 0;

            virtual void setFov(float fov) = 0;

            virtual void begin3dMode() = 0;

            virtual void end3dMode() = 0;


        private:


//////////////////////--------------------------/////////////////////////

    };

}
