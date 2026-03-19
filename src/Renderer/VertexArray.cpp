#include "Renderer/VertexArray.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Utils/Logger.hpp"

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

void VertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
{
	this->bind();
	vertexBuffer->bind();
	const Buffer& bufferLayout = vertexBuffer->getBufferLayout();
	if(bufferLayout.getBufferElements().empty())
		Logger::get().log(m_className, "Buffer elements is empty!", Logger::ErrType::ERROR);
}
