#include "Renderer/Shader.hpp"
#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
{
    std::string vertexSource = readFile(vertexPath);
    std::string fragmentSource = readFile(fragmentPath);

    std::uint32_t vertexShader = compileShader(GL_VERTEX_SHADER, vertexSource);
    std::uint32_t fragmentShader = compileShader(GL_FRAGMENT_SHADER, fragmentSource);

    linkProgram(vertexShader, fragmentShader);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

Shader::~Shader()
{
    if (m_rendererID != 0)
    {
        glDeleteProgram(m_rendererID);
    }
}

Shader::Shader(Shader&& other) noexcept
    : m_rendererID(other.m_rendererID), m_uniformLocationCache(std::move(other.m_uniformLocationCache))
{
    other.m_rendererID = 0;
}

Shader& Shader::operator=(Shader&& other) noexcept
{
    if (this != &other)
    {
        if (m_rendererID != 0)
        {
            glDeleteProgram(m_rendererID);
        }
        m_rendererID = other.m_rendererID;
        m_uniformLocationCache = std::move(other.m_uniformLocationCache);
        other.m_rendererID = 0;
    }
    return *this;
}

void Shader::bind() const
{
    glUseProgram(m_rendererID);
}

void Shader::unbind() const
{
    glUseProgram(0);
}

std::string Shader::readFile(const std::string& filepath)
{
    std::ifstream file(filepath);
    if (!file.is_open())
    {
        std::cerr << "[Shader Error] Failed to open file: " << filepath << std::endl;
        return "";
    }
    std::stringstream stream;
    stream << file.rdbuf();
    return stream.str();
}

std::uint32_t Shader::compileShader(std::uint32_t type, const std::string& source)
{
    std::uint32_t shaderID = glCreateShader(type);
    const char* src = source.c_str();
    glShaderSource(shaderID, 1, &src, nullptr);
    glCompileShader(shaderID);

    std::int32_t success;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        std::int32_t maxLength = 0;
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
        std::string infoLog(maxLength, ' ');
        glGetShaderInfoLog(shaderID, maxLength, &maxLength, &infoLog[0]);
        glDeleteShader(shaderID);
        return 0;
    }

    return shaderID;
}

void Shader::linkProgram(std::uint32_t vertexShader, std::uint32_t fragmentShader)
{
    m_rendererID = glCreateProgram();
    glAttachShader(m_rendererID, vertexShader);
    glAttachShader(m_rendererID, fragmentShader);
    glLinkProgram(m_rendererID);

    std::int32_t success;
    glGetProgramiv(m_rendererID, GL_LINK_STATUS, &success);
    if (!success)
    {
        std::int32_t maxLength = 0;
        glGetProgramiv(m_rendererID, GL_INFO_LOG_LENGTH, &maxLength);
        std::string infoLog(maxLength, ' ');
        glGetProgramInfoLog(m_rendererID, maxLength, &maxLength, &infoLog[0]);

        std::cerr << "[Shader Linking Error]:\n" << infoLog << std::endl;
        glDeleteProgram(m_rendererID);
        m_rendererID = 0;
    }
}

std::int32_t Shader::getUniformLocation(const std::string& name)
{
    if (m_uniformLocationCache.find(name) != m_uniformLocationCache.end())        
        return m_uniformLocationCache[name];

    std::int32_t location = glGetUniformLocation(m_rendererID, name.c_str());
    m_uniformLocationCache[name] = location;
    return location;
}

void Shader::setInt(const std::string& name, int value) { glUniform1i(getUniformLocation(name), value); }
void Shader::setFloat(const std::string& name, float value) { glUniform1f(getUniformLocation(name), value); }
void Shader::setVec3(const std::string& name, const glm::vec3& value) { glUniform3fv(getUniformLocation(name), 1, glm::value_ptr(value)); }
void Shader::setVec4(const std::string& name, const glm::vec4& value) { glUniform4fv(getUniformLocation(name), 1, glm::value_ptr(value)); }
void Shader::setMat4(const std::string& name, const glm::mat4& value) { glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value)); }