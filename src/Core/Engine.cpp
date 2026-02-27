#include "Core/Engine.hpp"

#include <glad/glad.h>
#include <stdexcept>
#include <memory>
#include "Utils//Logger.hpp"

Engine::Engine() {}

Engine::~Engine()
{
    glfwTerminate();
}

void Engine::init()
{
	m_scenemanager.addScene(SceneID::MAIN_SCENE, std::make_unique<Scene>());
}

void Engine::run()
{
while(!glfwWindowShouldClose(m_window.GetWindow()))
  {
    float m_currentFrame = glfwGetTime();
    float m_deltaTime = m_currentFrame - m_lastFrame;
    m_lastFrame = m_currentFrame;

    m_scenemanager.update(m_deltaTime);
    m_window.pollEvents();
    m_window.swapBuffers();
  }
}
