#include "ECS/World.h"
#include "ECS/Entity.h"

World::World()
{

}

Entity World::createEntity(std::string tag)
{
	auto entity = m_registry.create();
	return Entity(entity, this);
}