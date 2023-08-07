// This file contains all the member variables and methods that handles the enemy

#pragma once

#include "raylib.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	void update();
	void render();

private:
	void initTextures();
	void initVariables();

	void unload();
};