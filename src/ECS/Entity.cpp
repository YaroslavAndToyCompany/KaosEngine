#include "ECS/Entity.hpp"
#include "ECS/World.hpp"

Entity::Entity(entt::entity handler, World* world) : 
	m_entityHandler(handler), m_world(world)
{
}
