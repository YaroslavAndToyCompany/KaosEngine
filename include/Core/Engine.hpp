#pragma once
#include "Core/Window.hpp"

class Engine 
{
public:
    Engine(Window&& window);
    ~Engine();

    Engine(const Engine&) = delete;
    Engine& operator=(const Engine&) = delete;

private:
    Window m_window;

    static constexpr const char* m_className = "Engine";
};