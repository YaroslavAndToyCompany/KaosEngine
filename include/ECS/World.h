#pragma once
#include <string>
#include "entt\entt.hpp"

class Entity;

class World
{
public:
	World();

	Entity createEntity(std::string tag);

	entt::registry& reg() { return m_registry; }
private:
	entt::registry m_registry;

	friend class Entity;
	friend class System;
};