#pragma once
#include <vector>
#include "Renderer/VertexBuffer.hpp"

class VertexArray 
{
public:
	VertexArray();

	void bind();
	void addVertexBuffer();
private:
	uint32_t m_rendererID;
	std::vector<VertexBuffer*> m_vertexBuffers;
};