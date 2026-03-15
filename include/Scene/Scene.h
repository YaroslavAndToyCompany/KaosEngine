#pragma once
#include "ECS/World.h"
#include "ECS\RenderSystem.h"

class Scene 
{
public:
	Scene();

	virtual void onEnter();
	virtual void onExit();
	virtual void updateScene(float dt);
private:
	World m_world;
	RenderSystem m_renderer;

	static constexpr const char* m_className = "Scene";
};
