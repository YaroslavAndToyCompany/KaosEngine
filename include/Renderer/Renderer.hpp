#pragma once
#include <glm/glm.hpp>

class Renderer 
{
public:
	static void init();
	static void beginScene();
	static void endScene();

	//primitives
	static void drawQuad(glm::vec2& position, glm::vec2& size, glm::vec4& color);
	static void drawRectangle(glm::vec2& position, glm::vec2& size, glm::vec4& color);
	static void drawCircle(glm::vec2& position, glm::vec2& radius, glm::vec4& color);
private:

};
