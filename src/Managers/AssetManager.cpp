#include "Managers/AssetManager.hpp"

AssetHandle AssetManager::loadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
{
    auto it = m_shaderNameToHandle.find(name);
    if (it != m_shaderNameToHandle.end())
    {
        return it->second;
    }

    AssetHandle handle = m_shaders.insert(vertexPath, fragmentPath);
    m_shaderNameToHandle[name] = handle;
    return handle;
}

void AssetManager::unloadShader(AssetHandle handle)
{
    for (auto it = m_shaderNameToHandle.begin(); it != m_shaderNameToHandle.end(); ++it)
    {
        if (it->second.m_index == handle.m_index && it->second.m_generation == handle.m_generation)
        {
            m_shaderNameToHandle.erase(it);
            break;
        }
    }
    m_shaders.erase(handle);
}

void AssetManager::unloadShader(const std::string& name)
{
    auto it = m_shaderNameToHandle.find(name);
    if (it != m_shaderNameToHandle.end())
    {
        m_shaders.erase(it->second);
        m_shaderNameToHandle.erase(it);
    }
}

const Shader* AssetManager::getShader(AssetHandle handle) const
{
    return m_shaders.get(handle);
}

Shader* AssetManager::getShader(AssetHandle handle)
{
    return m_shaders.get(handle);
}

AssetHandle AssetManager::getShaderHandle(const std::string& name) const
{
    auto it = m_shaderNameToHandle.find(name);
    if (it != m_shaderNameToHandle.end())
    {
        return it->second;
    }
    return AssetHandle();
}

AssetHandle AssetManager::loadTexture(const std::string& name, const std::string& path)
{
    auto it = m_textureNameToHandle.find(name);
    if (it != m_textureNameToHandle.end())
    {
        return it->second;
    }

    AssetHandle handle = m_textures.insert();
    Texture* texture = m_textures.get(handle);
    if (texture)
    {
        TextureSpecs specs{};
        texture->loadTexture(specs, path);
    }

    m_textureNameToHandle[name] = handle;
    return handle;
}

void AssetManager::unloadTexture(AssetHandle handle)
{
    for (auto it = m_textureNameToHandle.begin(); it != m_textureNameToHandle.end(); ++it)
    {
        if (it->second.m_index == handle.m_index && it->second.m_generation == handle.m_generation)
        {
            m_textureNameToHandle.erase(it);
            break;
        }
    }
    m_textures.erase(handle);
}

void AssetManager::unloadTexture(const std::string& name)
{
    auto it = m_textureNameToHandle.find(name);
    if (it != m_textureNameToHandle.end())
    {
        m_textures.erase(it->second);
        m_textureNameToHandle.erase(it);
    }
}

const Texture* AssetManager::getTexture(AssetHandle handle) const
{
    return m_textures.get(handle);
}

Texture* AssetManager::getTexture(AssetHandle handle)
{
    return m_textures.get(handle);
}

AssetHandle AssetManager::getTextureHandle(const std::string& name) const
{
    auto it = m_textureNameToHandle.find(name);
    if (it != m_textureNameToHandle.end())
    {
        return it->second;
    }
    return AssetHandle();
}