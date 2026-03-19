#include "Renderer/Buffer.hpp"

Buffer::Buffer(std::initializer_list<BufferElements> bufferelements) 
	: m_bufferelements(bufferelements)
{
	calcuteOffsetAndStride();
}

void Buffer::calcuteOffsetAndStride()
{
	size_t offset = 0;
	m_stride = 0;
	for(BufferElements& element : m_bufferelements)
	{
		element.m_offset = offset;
		offset += element.m_size;
		m_stride += element.m_size;
	}
}