#include "Managers/SceneManager.hpp"
#include "Utils/Logger.hpp"

SceneManager::SceneManager()
{
	Logger::get().log(m_className, "Mark is called");
}

void SceneManager::addScene(SceneID sceneID, std::unique_ptr<Scene> scene)
{
	m_scenes.emplace(sceneID, std::move(scene));
}

void SceneManager::switchTo(SceneID SceneID)
{
	auto activeScene = m_scenes.find(SceneID);
	
	if(activeScene != m_scenes.end())
	{
		if (m_activeScene)
			m_activeScene->onExit();
		
		m_activeScene = activeScene->second.get();
		m_activeScene->onEnter();
	}
}

void SceneManager::update(float dt)
{
	m_activeScene->updateScene(dt);
}
