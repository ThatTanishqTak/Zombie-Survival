// This file acts as the template to base the player and the enemy off

#pragma once

#include "raylib.h"

class BaseChar
{
public:
	BaseChar();
	~BaseChar();

	void update();
	void render();

private:
	void unload();
};