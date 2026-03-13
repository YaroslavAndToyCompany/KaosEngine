#include "Managers/SceneManager.h"
#include "Utils/Logger.hpp"

SceneManager::SceneManager()
{
	Logger::get()->log(m_className, "Mark is called");
}

void SceneManager::addScene(SceneID sceneID, std::unique_ptr<Scene> scene)
{
	m_scenes.emplace(sceneID, std::move(scene));
}

void SceneManager::switchTo(SceneID SceneID)
{
	auto activescene = m_scenes.find(SceneID);
	
	if(activescene != m_scenes.end())
	{
		if (m_activescene)
			m_activescene->onExit();
		
		m_activescene = activescene->second.get();
		m_activescene->onEnter();
	}
}

void SceneManager::update(float dt)
{
	m_activescene->updateScene(dt);
}
