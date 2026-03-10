#include "Core/Engine.hpp"

#include <glad/glad.h>
#include <memory>

Engine::Engine() {}

Engine::~Engine() {}

void Engine::init()
{
	m_sceneManager.addScene(SceneID::MAIN_SCENE, std::make_unique<Scene>());
    m_sceneManager.switchTo(SceneID::MAIN_SCENE);
}

void Engine::run()
{
    while(!m_window.shouldClose())
    {
        float m_currentFrame = glfwGetTime();
        float m_deltaTime = m_currentFrame - m_lastFrame;
        m_lastFrame = m_currentFrame;

        m_sceneManager.update(m_deltaTime);
        m_window.pollEvents();
        m_window.swapBuffers();
    }
}
