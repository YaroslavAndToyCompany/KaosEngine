#pragma once

#include <string>
#include <cstdint>

struct TextureSpecs
{
    std::uint32_t m_width = 0;
    std::uint32_t m_height = 0;
};

class Texture
{
public:
    Texture();
    ~Texture();

    Texture(const Texture&) = delete;
    Texture& operator=(const Texture&) = delete;
    Texture(Texture&& other) noexcept;
    Texture& operator=(Texture&& other) noexcept;

    void bind() const;
    void unbind() const;

    void loadTexture(const TextureSpecs& specification, const std::string& path);
private:
    std::uint32_t m_TextureID = 0;
};