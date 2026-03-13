#include "scene/Scene.h"
#include "ECS\Entity.h"
#include "ECS\Components.h"
#include <iostream>

Scene::Scene() 
{

}

void Scene::onEnter() 
{
	auto player = m_world.createEntity("player");
	player.addComponent<TransformComponent>();
	std::cout << "Scene mark is called\n";
}

void Scene::onExit()
{

}

void Scene::updateScene(float dt)
{
	m_renderer.update(dt, m_world);
}
