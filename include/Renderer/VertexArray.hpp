#pragma once
#include <vector>
#include <memory>
#include "Renderer/VertexBuffer.hpp"

class VertexArray 
{
public:
	VertexArray();

	void bind();
	void unbind();
	void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer);
private:
	uint32_t m_rendererID;
	uint32_t m_vboIndexCounter = 0;
	std::vector<std::shared_ptr<VertexBuffer>> m_vertexBuffers;
	
	static constexpr const char* m_className = "VertexArray";
};