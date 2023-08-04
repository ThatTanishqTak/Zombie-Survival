// This file contains all the member functions and methods important to run the game

#pragma once

#include <iostream>
#include "raylib.h"
#include "graphics.h"

class graphics;

class Game
{
public:
	Game(Graphics* graphics);
	~Game();

	void run();

	int windowWidth, windowHeight;

private:
	Graphics* grp_obj;

	void initVariables();
	void initTextures();
	void initScreen();

	void update();
	void render();

	void unload();
};