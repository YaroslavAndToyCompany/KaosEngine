#include "Core/Engine.hpp"

#include <glad/glad.h>
#include <stdexcept>

#include "Utils//Logger.hpp"

Engine::Engine(Window&& window)
    : m_window(std::move(window))
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        Logger::getInstance()->log(m_className, "Failed to initialize GLAD", Logger::ErrType::ERROR);
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

Engine::~Engine()
{
    glfwTerminate();
}