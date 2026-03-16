#pragma once
#include "ECS/System.hpp"

class World;

class RenderSystem : public System 
{
public:
	RenderSystem();

	virtual void update(float deltatime, World& world) override;

private:
	
};