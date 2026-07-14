#include "Renderer/Renderer.hpp"
#include "Renderer/VertexArray.hpp"
#include "Renderer/Shader.hpp"
#include <glad/glad.h>

void Renderer::init()
{
}

void Renderer::beginScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::endScene()
{
}

void Renderer::draw(VertexArray* vertexArray, Shader* shader)
{
    vertexArray->bind();
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);
}