#include "Renderer/Buffer.hpp"

Buffer::Buffer(std::initializer_list<BufferElements> bufferElements) 
	: m_bufferElements(bufferElements)
{
	calcuteOffsetAndStride();
}

void Buffer::calcuteOffsetAndStride()
{
	size_t offset = 0;
	m_stride = 0;
	for(BufferElements& element : m_bufferElements)
	{
		element.m_offset = offset;
		offset += element.m_size;
		m_stride += element.m_size;
	}
}