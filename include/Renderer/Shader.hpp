#pragma once
#include <string>
#include <cstdint>

class Shader
{
public:
	Shader(std::uint32_t shaderType, const std::string& sourceCode);
	~Shader();

private:
	std::uint32_t m_handler;
};
