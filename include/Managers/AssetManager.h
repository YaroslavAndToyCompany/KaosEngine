#pragma once
#include "Utils/SlotMap.h"


class AssetManager 
{
public:
	AssetManager();
	~AssetManager();

	void loadTexture();
	void unloadTexture();
    //Texture GetTexture() {return texture;}
};