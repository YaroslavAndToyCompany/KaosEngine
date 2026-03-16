#pragma once
#include <entt/entt.hpp>
#include "ECS/World.hpp"


class System 
{
public:
	virtual void update(float deltatime, World& world) = 0;

	template<typename... Components, typename Func>
	void viewComp(World& world, Func func)
	{
		auto view = world.m_registry.view<Components...>();
		for (auto entity : view)
		{
			func(entity, view.template get<Components>(entity)...);
		}
	}
};
