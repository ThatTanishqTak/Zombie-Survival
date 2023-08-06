// This file contains all the member functions and methods important to run the game

#pragma once // Make sure that include happen only once

#include <iostream>
#include "raylib.h"
#include "graphics.h"
#include "player.h"

class Graphics;
class Player;

class Game
{
public:
	Game(); // Constructor
	~Game(); // Destructor

	void run(); // The function that runs the game

	int windowWidth, windowHeight; // Declare window dimensions

private:
	// Declare all the pointers to the object for all the different classes
	Graphics* grp_obj;
	Player* ply_obj;

	// Initialization functions
	void initVariables();
	void initScreen();

	// Main loop functions
	void update();
	void render();

	// Destructor function
	void unload();
};