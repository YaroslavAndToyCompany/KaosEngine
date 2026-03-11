#include "Core/Window.hpp"

#include <stdexcept>
#include <utility>

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
        Logger::get()->log(m_className, "Failed to create GLFW window", Logger::ErrType::ERROR);
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

Window::Window(Window&& other) noexcept 
    : m_window(std::exchange(other.m_window, nullptr)),
      m_size(std::exchange(other.m_size, {0, 0})),
      m_title(std::move(other.m_title))
{}

Window& Window::operator=(Window&& other) noexcept
{
    Window(std::move(other)).swap(*this);
    return *this;
}

void Window::swap(Window& other)
{
    std::swap(m_window, other.m_window);
    std::swap(m_size, other.m_size);
    std::swap(m_title, other.m_title);
}

void Window::gladLoader()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		Logger::get()->log(m_className, "Failed to initialize GLAD", Logger::ErrType::ERROR);
		throw std::runtime_error("Failed to initialize GLAD");
	}
}

void Window::swapBuffers()
{
    glfwSwapBuffers(m_window);
}

void Window::pollEvents()
{
    glfwPollEvents();
}
