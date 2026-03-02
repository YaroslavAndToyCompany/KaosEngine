#pragma once
#include "entt/entt.hpp"
#include "ECS/World.h"
#include "Utils/Logger.hpp"

class Entity
{
public:
	Entity() = default;
	Entity(entt::entity handle, World* world);
	Entity(const Entity& other) = default;

    template<typename T, typename... Args>
	T& addComponent(Args&&... args) 
	{
		if(!hasComponent<T>())
			Logger::getInstance()->log(m_className, "Entity has already component", Logger::ErrType::ERROR);
		return m_world->m_registry.emplace<T>(m_EntityHandler, std::forward<Args>(Args)...);
	}

	template<typename T>
	T& getComponent()
	{
		return m_world->m_registry.get<T>(m_EntityHandler);
	}

	template<typename T>
	bool hasComponent() 
	{
		return m_world->m_registry.all_of<T>(m_EntityHandler);
	}
private:
	entt::entity m_EntityHandler{ entt::null };
	World* m_world = nullptr;
	static constexpr const char* m_className = "Entity";
};