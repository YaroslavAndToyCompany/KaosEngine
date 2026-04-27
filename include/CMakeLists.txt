# Variable for keeping header files
set(KAOS_ENGINE_HEADERS
    include/Core/Engine.hpp
    include/Core/Window.hpp

    include/ECS/Components.hpp
    include/ECS/Entity.hpp
    include/ECS/RenderSystem.hpp
    include/ECS/System.hpp
    include/ECS/World.hpp

    include/Managers/AssetManager.hpp
    include/Managers/SceneManager.hpp

    include/Memory/SizeBasedArena.hpp
    include/Memory/StackAllocator.hpp

    include/Renderer/Buffer.hpp
    include/Renderer/Renderer.hpp
    include/Renderer/Shader.hpp
    include/Renderer/Texture.hpp
    include/Renderer/VertexArray.hpp
    include/Renderer/VertexBuffer.hpp

    include/Scene/Scene.hpp

    include/Utils/Logger.hpp
    include/Utils/SlotMap.hpp

    PARENT_SCOPE
)
