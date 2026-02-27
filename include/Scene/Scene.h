#pragma once

class Scene 
{
public:
	Scene();

	virtual void onEnter();
	virtual void onExit();
	virtual void updateScene();
private:
};