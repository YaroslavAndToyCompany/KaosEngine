#include "Renderer/Shader.hpp"
#include <glad/glad.h>

Shader::Shader(unsigned int shaderType, const std::string& sourceCode)
{
	m_handler = glCreateProgram();
	const char* data = sourceCode.c_str();
	glShaderSource(m_handler, 1, &data, NULL);

	//dodaty debug huinu dlya source coda shaderiv!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	glCompileShader(m_handler);
}

Shader::~Shader()
{
	glDeleteProgram(m_handler);
}
