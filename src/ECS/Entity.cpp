#include "ECS/Entity.hpp"
#include "ECS/World.hpp"

Entity::Entity(entt::entity handler, World* world) : 
	m_EntityHandler(handler), m_world(world)
{
}
