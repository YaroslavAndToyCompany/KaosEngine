#pragma once
#include "ECS/World.h"

class Scene 
{
public:
	Scene();

	virtual void onEnter();
	virtual void onExit();
	virtual void updateScene();
private:
	World m_world;
};