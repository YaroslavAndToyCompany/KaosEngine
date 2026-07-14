#pragma once

#include <string>
#include <cstdint>
#include <unordered_map>
#include <glm/glm.hpp>

class Shader
{
public:
    Shader(const std::string& vertexPath, const std::string& fragmentPath);
    ~Shader();
    Shader(const Shader&) = delete;
    Shader& operator=(const Shader&) = delete;
    Shader(Shader&& other) noexcept;
    Shader& operator=(Shader&& other) noexcept;

    void bind() const;
    void unbind() const;

    void setInt(const std::string& name, int value);
    void setFloat(const std::string& name, float value);
    void setVec3(const std::string& name, const glm::vec3& value);
    void setVec4(const std::string& name, const glm::vec4& value);
    void setMat4(const std::string& name, const glm::mat4& value);
private:
    std::string readFile(const std::string& filepath);
    std::uint32_t compileShader(std::uint32_t type, const std::string& source);
    void linkProgram(std::uint32_t vertexShader, std::uint32_t fragmentShader);
    std::int32_t getUniformLocation(const std::string& name);
private:
    std::uint32_t m_rendererID = 0;
    std::unordered_map<std::string, std::int32_t> m_uniformLocationCache;
};