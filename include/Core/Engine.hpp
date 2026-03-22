#pragma once
#include "Core/Window.hpp"
#include "Managers/SceneManager.hpp"

class Engine 
{
public:
    Engine();
    ~Engine();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    void init();
    void run();
private:
    Window m_window;
    SceneManager m_sceneManager;
    float m_lastFrame = 0.0f;

    static constexpr const char* m_className = "Engine";
};