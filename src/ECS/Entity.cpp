#include "ECS/Entity.h"
#include "ECS\World.h"

Entity::Entity(entt::entity handler, World* world) : 
	m_EntityHandler(handler), m_world(world)
{
}
