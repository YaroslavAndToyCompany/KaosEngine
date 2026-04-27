cmake_minimum_required(VERSION 3.12)

project(
    KaosEngine
    DESCRIPTION "A graphical engine created on C++ plus OpenGL"
    LANGUAGES CXX C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendors)
add_subdirectory(include)
add_subdirectory(src)

add_executable(${PROJECT_NAME}
    ${KAOS_ENGINE_HEADERS}
    ${KAOS_ENGINE_SOURCES}
)

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
