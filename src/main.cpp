#include "Core/Window.hpp"
#include "Core/Engine.hpp"

int main() {
    Window m_window;
    m_window.setTitle("Super");

    Engine engine(std::move(m_window));
    return 0;
}
