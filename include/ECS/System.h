#pragma once
#include <entt/entt.hpp>

class World;

class System 
{
public:
	virtual void update(float deltatime) = 0;
private:
	template<typename... Components, typename Func>
	void viewComp(World& world, Func)
	{
		auto view = world.m_registry.view<Components...>();
		for (auto entity : view)
		{
			func(entity, view.template get<Components>(entity)...);
		}
	}
};