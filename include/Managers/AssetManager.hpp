#pragma once

#include <string>
#include <unordered_map>
#include "Utils/SlotMap.hpp"
#include "Renderer/Shader.hpp"
#include "Renderer/Texture.hpp"

class AssetManager
{
public:
    AssetManager() = default;
    ~AssetManager() = default;

    AssetManager(const AssetManager&) = delete;
    AssetManager& operator=(const AssetManager&) = delete;

    AssetHandle loadShader(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
    void unloadShader(AssetHandle handle);
    void unloadShader(const std::string& name);

    const Shader* getShader(AssetHandle handle) const;
    Shader* getShader(AssetHandle handle);
    AssetHandle getShaderHandle(const std::string& name) const;

    AssetHandle loadTexture(const std::string& name, const std::string& path);
    void unloadTexture(AssetHandle handle);
    void unloadTexture(const std::string& name);

    const Texture* getTexture(AssetHandle handle) const;
    Texture* getTexture(AssetHandle handle);
    AssetHandle getTextureHandle(const std::string& name) const;

private:
    SlotMap<Shader> m_shaders;
    SlotMap<Texture> m_textures;
    std::unordered_map<std::string, AssetHandle> m_shaderNameToHandle;
    std::unordered_map<std::string, AssetHandle> m_textureNameToHandle;
};