#include "scene/Scene.h"

Scene::Scene() {}

void Scene::onEnter() 
{
	auto player = m_world->createEntity("player");
	// player->AddComponent();
	// і так далі бялялялялял працювать з ентіті, потім зроблю нормалньл
}

void Scene::onExit()
{

}

void Scene::updateScene()
{

}
