#pragma once
#include "Scene/Scene.hpp"
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

	void addScene(SceneID sceneID, std::unique_ptr<Scene> scene);
	void switchTo(SceneID sceneID);
	void update(float dt);

private:
	std::map<SceneID, std::unique_ptr<Scene>> m_scenes;
	Scene* m_activescene = nullptr;

	static constexpr const char* m_className = "SceneManager";
};