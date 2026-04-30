#include "Renderer/Texture.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb_image.h>

Texture::Texture()
{
	glGenTextures(1, &m_TextureID);

}

void Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, m_TextureID);
}

void Texture::loadTexture(const TextureSpecs& specification, const std::string& path)
{

}

