#include "ECS/RenderSystem.hpp"
#include "ECS/Components.hpp"
#include "Utils/Logger.hpp"

RenderSystem::RenderSystem()
{
}

void RenderSystem::update(float deltatime, World& world)
{
	viewComp<TransformComponent>(world,
		[](auto entity, auto& transform)
		{
			Logger::get().log(m_className, Logger::ErrType::INFO, "Render update func is called");
		}
	);
}
