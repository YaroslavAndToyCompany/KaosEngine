#include "ECS/Entity.h"

Entity::Entity(entt::entity handler, World* world) : 
	m_EntityHandler(handler), m_world(world)
{
}
