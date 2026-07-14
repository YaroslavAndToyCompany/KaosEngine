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

void VertexArray::addVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer)
{
	this->bind();
	vertexBuffer->bind();
	const Buffer& bufferLayout = vertexBuffer->getBufferLayout();
	if (bufferLayout.getBufferElements().empty())
	{
		Logger::get().log(m_className, Logger::ErrType::ERROR, "Buffer elements is empty!");
		return;
	}

    for (const auto& element : bufferLayout.getBufferElements())
    {
        glEnableVertexAttribArray(m_vboIndexCounter);

        glVertexAttribPointer(m_vboIndexCounter, getComponentCount(element.m_type), dataTypetoGL(element.m_type), element.bIsNormalized ? GL_TRUE : GL_FALSE,
            bufferLayout.getStride(), reinterpret_cast<const void*>(element.m_offset));
        m_vboIndexCounter++;
    }

	m_vertexBuffers.push_back(std::move(vertexBuffer));
}

void VertexArray::setIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer)
{
	this->bind();
	indexBuffer->bind();
	m_indexBuffers.push_back(std::move(indexBuffer));
}
