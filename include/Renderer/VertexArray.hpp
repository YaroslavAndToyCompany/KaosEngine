#pragma once
#include <vector>
#include <memory>
#include <cstdint>
#include "Renderer/VertexBuffer.hpp"
#include "Renderer/IndexBuffer.h"

class VertexArray 
{
public:
	VertexArray();

	void bind();
	void unbind();
	void addVertexBuffer(std::unique_ptr<VertexBuffer> vertexBuffer);
	void setIndexBuffer(std::unique_ptr<IndexBuffer> indexBuffer);
private:
	std::uint32_t m_rendererID;
	std::uint32_t m_vboIndexCounter = 0;
	std::vector<std::unique_ptr<VertexBuffer>> m_vertexBuffers;
	std::vector<std::unique_ptr<IndexBuffer>> m_indexBuffers;
	
	static constexpr const char* m_className = "VertexArray";
};
