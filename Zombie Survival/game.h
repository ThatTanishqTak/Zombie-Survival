// This file contains all the member functions and methods important to run the game

#pragma once

#include <iostream>
#include "raylib.h"

class Game
{
public:
	Game();
	~Game();

	void run();

	int windowWidth, windowHeight;

private:
	void update();
	void render();

	void initVariables();
	void initTextures();
	void initScreen();

	void unload();
};