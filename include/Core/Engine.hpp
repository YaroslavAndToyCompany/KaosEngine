#pragma once
#include "Core/Window.hpp"

class Engine 
{
public:
    Engine();
    ~Engine();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

    void run();
private:
    Window m_window;

    bool bIsRunning = true;
    static constexpr const char* m_className = "Engine";
};