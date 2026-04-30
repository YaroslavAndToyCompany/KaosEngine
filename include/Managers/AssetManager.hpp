#pragma once
#include "Utils/SlotMap.hpp"


class AssetManager 
{
public:
	AssetManager();
	~AssetManager();

	void loadTexture();
	void unloadTexture();
    //Texture GetTexture() {return texture;}
};
