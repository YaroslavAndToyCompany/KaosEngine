#include "ECS/World.hpp"
#include "ECS/Entity.hpp"
#include "Utils/Logger.hpp"

World::World()
{

}

Entity World::createEntity(std::string tag)
{
	auto entity = m_registry.create();
	Logger::get()->log(m_className, "Entity is created");
	return Entity(entity, this);
}