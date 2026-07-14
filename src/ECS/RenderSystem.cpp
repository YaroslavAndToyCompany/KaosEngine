#include "ECS/RenderSystem.hpp"
#include "ECS/Components.hpp"
#include "Renderer/Renderer.hpp"
#include "Managers/AssetManager.hpp"

RenderSystem::RenderSystem(AssetManager& assetManager)
    : m_assetManager(assetManager)
{
}

void RenderSystem::update(float deltatime, World& world)
{
    viewComp<MeshComponent>(world,
        [&](auto entity, auto& mesh)
        {
            Shader* shader = m_assetManager.getShader(mesh.shaderHandle);
            if (shader && mesh.vertexArray)
            {
                shader->bind();
                shader->setVec4("u_Color", glm::vec4(1.0f, 0.3f, 0.3f, 1.0f));
                Renderer::draw(mesh.vertexArray.get(), shader);
            }
        }
    );
}