#include "Core/Engine.hpp"

#include <glad/glad.h>
#include <stdexcept>

#include "Utils//Logger.hpp"

Engine::Engine() {}

Engine::~Engine()
{
    glfwTerminate();
}

void Engine::run()
{
while(bIsRunning)
  {
    m_window.pollEvents();
    m_window.swapBuffers();
  }
}
