#include "ECS\RenderSystem.h"
#include "ECS\Components.h"
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
