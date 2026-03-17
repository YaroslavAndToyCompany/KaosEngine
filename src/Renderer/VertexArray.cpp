#include "Renderer/VertexArray.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

VertexArray::VertexArray()
{
	glGenVertexArrays(1, &m_rendererID);
}

void VertexArray::bind()
{
	glBindVertexArray(m_rendererID);
}

void VertexArray::unbind()
{
	glBindVertexArray(0);
}

void VertexArray::addVertexBuffer()
{
	
}
