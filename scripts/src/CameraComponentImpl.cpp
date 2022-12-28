/*
** EPITECH PROJECT, 2022
** CameraImpl.cpp
** File description:
** CameraImpl.cpp
*/

#include "../include/CameraComponentImpl.hpp"


namespace polymorph::engine::render
{
    bool CameraImpl::isTargetingObject()
    {
        return (TargetType == Object);
    }

    engine::GameObject CameraImpl::getTargetObject()
    {
        return ObjectTarget;
    }

    void CameraImpl::setTargetPosition(engine::Vector3 targetPosition)
    {
        PointTarget = targetPosition;
        camera->setTarget(PointTarget);
        TargetType = CameraImpl::Point;
    }

    void CameraImpl::setUp(engine::Vector3 up)
    {
        camera->setUp(up);
    }

    void CameraImpl::setFov(float fov)
    {
        camera->setFOV(fov);
    }

    void CameraImpl::begin3dMode()
    {
        camera->begin3DMode();
    }

    void CameraImpl::end3dMode()
    {
        camera->end3DMode();
    }

    void CameraImpl::update()
    {
        if (TargetType == CameraTargetType::Object && !!ObjectTarget)
        {
            camera->setTarget(ObjectTarget->transform->getPosition());
        }
        else if (TargetType == Point)
        {
            camera->setTarget(PointTarget);
        }
    }

    void CameraImpl::start()
    {
        if (TargetType == CameraTargetType::Object && !!ObjectTarget)
        {
            camera->setTarget(ObjectTarget->transform->getPosition());
        }
        else if (TargetType == Point)
        {
            camera->setTarget(PointTarget);
        }
    }

    void CameraImpl::setTargetObject(engine::GameObject object)
    {
        ObjectTarget = object;
        camera->setTarget(ObjectTarget->transform->getPosition());
        TargetType = CameraImpl::Object;
    }

    void CameraImpl::build()
    {
        _setProperty("TargetType", TargetType);
        _setProperty("ObjectTarget", ObjectTarget);
        _setProperty("PointTarget", PointTarget);
        _setProperty("camera", camera);
    }

    void CameraImpl::saveAll()
    {
        saveProperty("TargetType", TargetType);
        saveProperty("ObjectTarget", ObjectTarget);
        saveProperty("PointTarget", PointTarget);
        saveProperty("camera", camera);
    }
}