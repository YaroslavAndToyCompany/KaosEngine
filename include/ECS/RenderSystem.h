#pragma once
#include "ECS/System.h"

class World;

class RenderSystem : public System 
{
public:
	RenderSystem();

	virtual void update(float deltatime, World& world) override;

private:
	
};