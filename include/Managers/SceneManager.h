#pragma once
#include "scene/Scene.h"
#include <map>
#include <memory>

enum class SceneID
{
	MAIN_SCENE
};

class SceneManager
{
public:
	SceneManager();

	void addScene(SceneID m_sceneID, std::unique_ptr<Scene> m_scene);
	void switchTo(SceneID);
	void update(float m_deltaTime);

private:
	std::map<SceneID, std::unique_ptr<Scene>> m_scenes;
	Scene* m_activescene = nullptr;
};