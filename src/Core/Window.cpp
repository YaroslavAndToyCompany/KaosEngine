#include "Core/Window.hpp"

#include <stdexcept>

#include "Utils/Logger.hpp"

Window::Window()
    :  Window(glm::vec2(800, 600), "Kaos App")
{}

Window::Window(glm::vec2 size, const std::string& title) 
    : m_size(size), m_title(title)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    m_window = glfwCreateWindow(m_size.x, m_size.y, m_title.c_str(), NULL, NULL);
    if (m_window == NULL)
    {
        Logger::getInstance()->log(m_className, "Failed to create GLFW window", Logger::ErrType::ERROR);
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);
}

Window::~Window()
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}