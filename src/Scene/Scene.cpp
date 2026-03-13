#include "Scene/Scene.h"
#include "ECS/Entity.h"
#include "ECS/Components.h"
#include "Utils/Logger.hpp"

Scene::Scene() 
{

}

void Scene::onEnter() 
{
	auto player = m_world.createEntity("player");
	player.addComponent<TransformComponent>();
	Logger::get()->log(m_className, "Mark is called");
}

void Scene::onExit()
{

}

void Scene::updateScene(float dt)
{
	m_renderer.update(dt, m_world);
}
