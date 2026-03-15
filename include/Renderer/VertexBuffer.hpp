#pragma once
#include <cstdint>

class VertexBuffer
{
public:
	VertexBuffer(float* vertices, uint32_t size);
	void bind() const;
	void unbind() const;
private:
	uint32_t m_rendererID;
};