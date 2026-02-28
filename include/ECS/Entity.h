#pragma once
#include "entt/entt.hpp"

class Entity
{
public:
	Entity() = default;
	Entity(entt::entity handle) //, World* world);
	Entity(const Entity& other) = default;

    template<typename T, typename... Params>
	T& addComponent(Params&... params) 
	{
	// логіка додавання компонента, впадлу писать не чіпать нічо наху
	}
private:
	entt::entity m_EntityHandler{ entt::null };
	// поки що пуста хуйня, нічо не чіпать наху
	// World* m_World = nullptr;
};