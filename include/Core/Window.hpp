#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <string>

class Window 
{
public:
    Window();
    Window(glm::vec2 size, const std::string& title);
    ~Window();

private:
    GLFWwindow* m_window;

    glm::vec2 m_size;
    std::string m_title;

    static constexpr const char* m_className = "Window";
};