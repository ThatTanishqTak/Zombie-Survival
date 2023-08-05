// This file contains all the member functions and methods important to run the game

#pragma once // Make sure that include happen only once

#include <iostream>
#include "raylib.h"
#include "graphics.h"

class Graphics;

class Game
{
public:
	Game(); // Constructor
	~Game(); // Destructor

	void run(); // The function that runs the game

	int windowWidth, windowHeight; // Declare window dimensions

private:
	Graphics* grp_obj;

	// Initialization functions
	void initVariables();
	void initScreen();

	// Main loop functions
	void update();
	void render();

	// Destructor function
	void unload();
};