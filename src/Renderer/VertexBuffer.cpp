#include "Renderer/VertexBuffer.hpp"
#include <glad/glad.h>


VertexBuffer::VertexBuffer(float* vertices, uint32_t size)
{
	glGenBuffers(1, &m_rendererID);
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer()
{
	glDeleteBuffers(1, &m_rendererID);
}

void VertexBuffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
}


void VertexBuffer::unbind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::setBufferLayout(Buffer& layout)
{
	layout = m_layout;
}
