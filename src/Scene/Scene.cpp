#include "Scene/Scene.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Components.hpp"
#include "Utils/Logger.hpp"
#include "Renderer/Renderer.hpp"

Scene::Scene()
    : m_renderer(m_assetManager)
{
}

void Scene::onEnter()
{
    Logger::get().log(m_className, Logger::ErrType::INFO, "Entering Scene");
}

void Scene::onExit()
{
    Logger::get().log(m_className, Logger::ErrType::INFO, "Exiting Scene");
}

void Scene::updateScene(float dt)
{
    Renderer::beginScene();
    m_renderer.update(dt, m_world);
    Renderer::endScene();
}