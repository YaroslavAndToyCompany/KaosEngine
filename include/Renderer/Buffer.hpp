#pragma once
#include <string>
#include <vector>
#include <initializer_list>
#include <cstdint>
#include <glad/glad.h>

enum class ShaderType 
{
	None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};

//byte counts
static uint32_t dataTypeSize(ShaderType type) 
{
	switch(type)
	{
	case ShaderType::Float:    return 4;
	case ShaderType::Float2:   return 4 * 2;
	case ShaderType::Float3:   return 4 * 3;
	case ShaderType::Float4:   return 4 * 4;
	case ShaderType::Mat3:     return 4 * 3 * 3;
	case ShaderType::Mat4:     return 4 * 4 * 4;
	case ShaderType::Int:      return 4;
	case ShaderType::Int2:     return 4 * 2;
	case ShaderType::Int3:     return 4 * 3;
	case ShaderType::Int4:     return 4 * 4;
	case ShaderType::Bool:     return 1;
	}
	return 0;
}

//size counts
static uint32_t getComponentCount(ShaderType type)
{
	switch (type)
	{
	case ShaderType::Float:   return 1;
	case ShaderType::Float2:  return 2;
	case ShaderType::Float3:  return 3;
	case ShaderType::Float4:  return 4;
	case ShaderType::Mat3:    return 3;
	case ShaderType::Mat4:    return 4;
	case ShaderType::Int:     return 1;
	case ShaderType::Int2:    return 2;
	case ShaderType::Int3:    return 3;
	case ShaderType::Int4:    return 4;
	case ShaderType::Bool:    return 1;
	}
	return 0;
}

static GLenum dataTypetoGL(ShaderType type)
{
	switch (type)
	{
	case ShaderType::Float:   return GL_FLOAT;
	case ShaderType::Float2:  return GL_FLOAT;
	case ShaderType::Float3:  return GL_FLOAT;
	case ShaderType::Float4:  return GL_FLOAT;
	case ShaderType::Mat3:    return GL_FLOAT;
	case ShaderType::Mat4:    return GL_FLOAT;
	case ShaderType::Int:     return GL_INT;
	case ShaderType::Int2:    return GL_INT;
	case ShaderType::Int3:    return GL_INT;
	case ShaderType::Int4:    return GL_INT;
	case ShaderType::Bool:    return GL_BOOL;
	}
	return 0;
}

struct BufferElements
{
	std::string m_name;
	ShaderType m_type;
	uint32_t m_size;
	size_t m_offset;
	bool bIsNormalized;

	BufferElements(ShaderType type, const std::string& name, bool normilized = false) 
		: m_name(name), m_type(type), bIsNormalized(normilized) 
	{}
};


class Buffer
{
public:
	Buffer() {}
	Buffer(std::initializer_list<BufferElements> bufferelements);

	inline uint32_t getStride() const { return m_stride; }
	inline const std::vector<BufferElements> getBufferElements() const { return m_bufferelements; }
private:
	void calcuteOffsetAndStride();

	uint32_t m_stride = 0;
	std::vector<BufferElements> m_bufferelements;
};