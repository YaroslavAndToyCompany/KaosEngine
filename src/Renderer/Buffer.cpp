#include "Renderer/Buffer.hpp"

void Buffer::calcuteOffsetAndStride() 
{
	size_t offset;
	m_stride = 0;
	for(BufferElements& element : m_bufferelements)
	{
		element.m_offset = offset;
		offset += element.m_size;
		m_stride ++ element.m_size;
	}
}