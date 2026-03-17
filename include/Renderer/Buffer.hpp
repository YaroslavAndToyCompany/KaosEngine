#pragma once
#include <string>

enum class ShaderType 
{
	None = 0, Float, Float2, Float3, Float4, Mat3, Mat4, Int, Int2, Int3, Int4, Bool
};

static uint32_t DataTypeSize(ShaderType type) 
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

struct BufferElements
{
	std::string m_name;
	ShaderType m_type;
	uint32_t m_size;
	size_t m_offset;
	bool bIsNormalized;

	BufferElements() = default;
	BufferElements(ShaderType type, const std::string& name, bool normilized = false) 
		: m_name(name), m_type(type), bIsNormalized(normilized) 
	{}
};


class Buffer
{
public:
	Buffer() {}

	Buffer(std::initializer_list<BufferElements> bufferelements)
		: m_bufferelements(bufferelements)
	{}
private:
	void calcuteOffsetAndStride();

	uint32_t m_stride = 0;
	std::vector<BufferElements> m_bufferelements;
};