#include "Core/Engine.hpp"
#include "Memory/StackAllocator.hpp"
#include "Utils/Logger.hpp"

int main()
{
    Engine engine;
    engine.init();
    engine.run();
    return 0;
}
