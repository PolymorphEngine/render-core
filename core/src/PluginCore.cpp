#include "PluginCore.hpp"
#include "ComponentFactory.hpp"
#include "SerializableObjectFactory.hpp"
#include "polymorph/engine/api.hpp"
#include "polymorph/engine/core.hpp"
#include "polymorph/engine/config.hpp"
#include "VideoSettings.hpp"

namespace polymorph::engine::api
{
    PluginCore::PluginCore(config::XmlNode &data, Engine &game,
                           std::string PluginsPath)
            : APlugin(data, game, PluginsPath)
    {

    }
    void PluginCore::preUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        if (!_window->isOpen())
            _game.exit(0);
    }

    void PluginCore::updateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        _window->clearWindow();
        _window->beginDrawing();
    }

    void PluginCore::postUpdateInternalSystems(std::shared_ptr<Scene> &scene)
    {
        _window->endDrawing();
        _window->update();
    }

    void PluginCore::startScripts(std::shared_ptr<Scene> &scene)
    {
        auto settings = getConfig<render::VideoSettings>();
        settings->build();
        _window = std::make_shared<render::DisplayModule>(settings,
                _game.getTitle(), _game.getPluginManager());
        if (!_game.isDebugMode())
            _window->setLogLevel(5);
    }

    void PluginCore::endScripts(std::shared_ptr<Scene> &scene)
    {
    }

    void PluginCore::createConfig(std::vector<std::shared_ptr<APluginConfig>> &configs)
    {
        configs.push_back(std::make_shared<render::VideoSettings>(_game, assetManager.tryResolve("VideoSettings.pcf.config")));
    }

    std::unique_ptr<AComponentFactory> PluginCore::createComponentFactory()
    {
        return std::unique_ptr<AComponentFactory>(new ComponentFactory());
    }

    std::unique_ptr<ASerializableObjectFactory> PluginCore::createSerializableObjectFactory()
    {
        return std::unique_ptr<ASerializableObjectFactory>(new SerializableObjectFactory());
    }
}

EXPORT_MODULE polymorph::engine::api::APlugin *createPlugin(polymorph::engine::config::XmlNode &data,
                                                            polymorph::engine::Engine &game, std::string PluginsPath)
{
    return new polymorph::engine::api::PluginCore(data, game, std::move(PluginsPath));
}