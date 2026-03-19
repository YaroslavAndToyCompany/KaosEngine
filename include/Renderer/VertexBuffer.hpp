#pragma once
#include <cstdint>
#include "Renderer/Buffer.hpp"

class VertexBuffer
{
public:
	VertexBuffer(float* vertices, uint32_t size);
	VertexBuffer(const VertexBuffer&) = delete;
	VertexBuffer& operator=(const VertexBuffer&) = delete;
	~VertexBuffer();

	void bind() const;
	void unbind() const;
	void setBufferLayout(Buffer& layout);
	inline const Buffer& getBufferLayout() const { return m_layout; }
private:
	Buffer m_layout;
	uint32_t m_rendererID;
};