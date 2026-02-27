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

    Window(const Window&) = delete;
    Window& operator=(const Window&) = delete;

    Window(Window&& other) noexcept;
    Window& operator=(Window&& other) noexcept;

    bool shouldClose() { return glfwWindowShouldClose(m_window); }

    void setTitle(const std::string& title) { m_title = std::move(title); }
    void setSize(const glm::vec2 size) { m_size = size; }
    void setShouldClose(bool value) { glfwSetWindowShouldClose(m_window, value); }
    GLFWwindow* GetWindow() { return m_window; }
	void swapBuffers();
	void pollEvents();

private:
    void move(Window&& other);
    void gladLoader();
  
    GLFWwindow* m_window;

    glm::vec2 m_size;
    std::string m_title;

    static constexpr const char* m_className = "Window";
};