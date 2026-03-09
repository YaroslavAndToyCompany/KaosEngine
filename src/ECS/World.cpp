#include "ECS/World.h"
#include "ECS/Entity.h"
#include <iostream>

World::World()
{

}

Entity World::createEntity(std::string tag)
{
	auto entity = m_registry.create();
	std::cout << "Entity is created\n";
	return Entity(entity, this);
}