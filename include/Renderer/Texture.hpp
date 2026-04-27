#pragma once
#include <iostream>
#include <cstdint>
struct TextureSpecs
{
	uint32_t m_width;
	uint32_t m_height;
};

class Texture 
{
public:
	Texture();
	~Texture();

	void bind();

	void loadTexture(const TextureSpecs& specification, const std::string& path);
private:
	uint32_t m_TextureID;
protected:

};