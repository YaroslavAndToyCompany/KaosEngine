#pragma once
#include <vector>
#include <memory>
#include <cstdint>
#include "Renderer/VertexBuffer.hpp"

class VertexArray 
{
public:
	VertexArray();

	void bind();
	void unbind();
	void addVertexBuffer(const VertexBuffer* vertexBuffer);
private:
	std::uint32_t m_rendererID;
	std::uint32_t m_vboIndexCounter = 0;
	std::vector<std::unique_ptr<VertexBuffer>> m_vertexBuffers;
	
	static constexpr const char* m_className = "VertexArray";
};
