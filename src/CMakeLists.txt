# Variable for keeping source files
set(KAOS_ENGINE_SOURCES
    src/Core/Engine.cpp
    src/Core/Window.cpp

    src/ECS/Entity.cpp
    src/ECS/RenderSystem.cpp
    src/ECS/World.cpp

    src/Managers/SceneManager.cpp

    src/Memory/StackAllocator.cpp
    src/Memory/StackAllocatorContainer.cpp

    src/Scene/Scene.cpp

    src/Utils/Logger.cpp

    src/main.cpp

    PARENT_SCOPE
)
