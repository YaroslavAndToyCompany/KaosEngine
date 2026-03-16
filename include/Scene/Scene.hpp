#pragma once
#include "ECS/World.hpp"
#include "ECS/RenderSystem.hpp"

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
