cmake_minimum_required(VERSION 3.12)

project(
    KaosEngine
    DESCRIPTION "A graphical engine created on C++ plus OpenGL"
    LANGUAGES CXX C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendors)

file(GLOB_RECURSE PROJECT_SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE PROJECT_HEADERS "${CMAKE_SOURCE_DIR}/include/*.hpp")

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
 "include/Managers/SceneManager.hpp" "src/Managers/SceneManager.cpp" "include/Scene/Scene.hpp" "src/Scene/Scene.cpp"  "include/ECS/Entity.hpp" "src/ECS/Entity.cpp"  "include/ECS/Components.hpp" "include/ECS/World.hpp" "src/ECS/World.cpp"  "include/ECS/System.hpp"  "include/ECS/RenderSystem.hpp" "src/ECS/RenderSystem.cpp" "include/Renderer/Renderer.hpp" "src/Renderer/Renderer.cpp" "include/Renderer/VertexArray.hpp" "src/Renderer/VertexArray.cpp" "include/Renderer/VertexBuffer.hpp" "src/Renderer/VertexBuffer.cpp" "include/Renderer/Buffer.hpp" "src/Renderer/Buffer.cpp" "include/Renderer/Shader.hpp" "src/Renderer/Shader.cpp" "include/Managers/AssetManager.h" "include/Utils/SlotMap.h")

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
    COMPILE_WARNING_AS_ERROR OFF
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/include")

find_package(OpenGL REQUIRED)

target_link_libraries(KaosEngine PRIVATE glm::glm)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
    assimp
    EnTT::EnTT
    glad
    glfw
    glm::glm
    imgui
    stb_image
    OpenGL::GL
)