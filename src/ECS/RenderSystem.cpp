#include "ECS/RenderSystem.hpp"
#include "ECS/Components.hpp"
#include <iostream>

RenderSystem::RenderSystem()
{
}

void RenderSystem::update(float deltatime, World& world)
{
	viewComp<TransformComponent>(world,
		[](auto entity, auto& transform)
		{
			std::cout << "Render update func is called\n";
		}
	);
}
