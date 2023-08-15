// This file contain the member variables and methods to handle the player

#pragma once // Make sure that the include happens only once

#include "raylib.h"

class Player // This class will handle the player
{
public:
	Player(); // Constructor
	~Player(); // Destructor

	void update(); // Function to update the player
	void render(); // Function to render the player

private:
	void initTextures(); // Function to initialize the textures
	void initVariables(); // Function to initialize the variables

	// Define the variables to store the player textures
	Texture2D playerIdle;
	Texture2D playerRun;
	Texture2D playerJump;
	Texture2D playerAttack;
	Texture2D playerHurt;
	Texture2D playerDead;

	// Variables that handle player movement
	float moveSpeed, jumpForce, gravity;
	bool isOnGround;
	Vector2 playerPos;

	void unload(); // Function to handle memory management
};