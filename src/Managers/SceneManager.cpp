#include "Managers/SceneManager.h"
#include <iostream>

SceneManager::SceneManager()
{
	std::cout << "SceneManager mark is called\n";
}

void SceneManager::addScene(SceneID m_sceneID, std::unique_ptr<Scene> m_scene)
{
	m_scenes.emplace(m_sceneID, std::move(m_scene));
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
