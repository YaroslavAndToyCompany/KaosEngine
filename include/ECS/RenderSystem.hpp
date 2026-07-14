#pragma once
#include "ECS/System.hpp"

class World;
class AssetManager;

class RenderSystem : public System
{
public:
    RenderSystem(AssetManager& assetManager);

    virtual void update(float deltatime, World& world) override;

private:
    AssetManager& m_assetManager;
    static constexpr const char* m_className = "RenderSystem";
};