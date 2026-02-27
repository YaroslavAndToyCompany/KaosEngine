#include "Managers/SceneManager.h"

SceneManager::SceneManager()
{
}

void SceneManager::addScene(SceneID m_sceneID, std::unique_ptr<Scene> m_scene)
{
	m_scenes.emplace(m_sceneID, std::move(m_scene));
}

void SceneManager::switchTo(SceneID)
{
}

void SceneManager::update(float m_deltaTime)
{

}
