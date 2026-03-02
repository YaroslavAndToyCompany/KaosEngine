#pragma once
#include "ECS/Entity.h"

class Entity;

class World 
{
public:
	World();

	Entity createEntity(std::string& tag);

	entt::registry& reg() { return m_registry; }
private:
	entt::registry m_registry;
};