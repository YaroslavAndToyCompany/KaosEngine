#pragma once
#include "ECS/World.hpp"
#include "Managers/AssetManager.hpp"
#include "ECS/RenderSystem.hpp"

class Scene
{
public:
    Scene();

    virtual void onEnter();
    virtual void onExit();
    virtual void updateScene(float dt);

private:
    World m_world;
    AssetManager m_assetManager;
    RenderSystem m_renderer;

    static constexpr const char* m_className = "Scene";
};