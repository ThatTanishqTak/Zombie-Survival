// This file contains all the graphics for the UI

#pragma once

#include "raylib.h"

class Graphics
{
public:
	Graphics();
	~Graphics();

	Texture2D backgroundDay;
	Texture2D backgroundNight;

	void initVariables();
	void initTextures();

	void update();
	void render();

	void unload();

private:
};