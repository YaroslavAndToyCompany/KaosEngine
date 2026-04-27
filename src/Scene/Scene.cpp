#include "Scene/Scene.hpp"
#include "ECS/Entity.hpp"
#include "ECS/Components.hpp"
#include "Utils/Logger.hpp"

Scene::Scene() 
{

}

void Scene::onEnter() 
{
	auto player = m_world.createEntity("player");
	player.addComponent<TransformComponent>();
	Logger::get().log(m_className, Logger::ErrType::INFO, "Mark is called");
}

void Scene::onExit()
{

}

void Scene::updateScene(float dt)
{
	m_renderer.update(dt, m_world);
}
