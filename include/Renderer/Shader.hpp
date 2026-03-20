#pragma once
#include <string>

class Shader
{
public:
	Shader(unsigned int shaderType, const std::string& sourceCode);
	~Shader();

private:
	unsigned int m_handler;
};