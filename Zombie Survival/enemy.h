// This file contains all the member variables and methods that handles the enemy

#pragma once // Make sure that include happens only once

#include "raylib.h"

class Enemy // The class will handle the enemy
{
public:
	Enemy(); // Constructor
	~Enemy(); // Destructor

	void update(); // Function to update the enemy
	void render(); // Function to render the enemy

private:
	void initTextures(); // Function to initialize the textures
	void initVariables(); // Function to initialize the variables

	// Variables to store the enemy textures
	Texture2D enemyIdle;
	Texture2D enemyRun;
	Texture2D enemyJump;
	Texture2D enemyAttack;
	Texture2D enemyHurt;
	Texture2D enemyDead;

	void unload(); // Function to handle memory management
};