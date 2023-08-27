// This file contain the member variables and methods to handle the player

#pragma once // Make sure that the include happens only once

#include "raylib.h"
#include <iostream>

class Player // This class will handle the player
{
public:
	Player(); // Constructor
	~Player(); // Destructor

	void update(); // Function to update the player
	void render(); // Function to render the player

	// Variables that handle player movement
	float moveSpeed;
	Vector2 playerPos;

private:
	void initTextures(); // Function to initialize the textures
	void initVariables(); // Function to initialize the variables

	int updateAnimations(int maxFrame); // Function to handle all the animations

	int attack();

	int health, damage; // Define variables to store the player's health and the amount of damage the player can deal

	// Define the variables to store the player textures
	Texture2D playerTexture;
	Texture2D playerIdle;
	Texture2D playerRun;
	Texture2D playerAttack;
	Texture2D playerHurt;
	Texture2D playerDead;

	// Variables for animations
	int currentFrame;
	float runningTime, updateTime;

	int rightLeft;

	void unload(); // Function to handle memory management
};