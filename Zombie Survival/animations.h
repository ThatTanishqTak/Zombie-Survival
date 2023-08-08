// This file is header file for the animation manager

#pragma once // Make sure that include happens only once

#include "raylib.h"
#include "player.h"

class Player;

class Animations // This class will handle the animations
{
public:
	Animations(Texture2D texture, int rowFrame, int columnFrame, int framePerSecond); // Initialized constructor
	~Animations(); // Destructor

	void update(); // Update function
	void render(float x, float y); // Initialized render function

private:
	Player* anim_ply_obj; // Declare the player object to be used in the animations class

	void initTextures(); // Function to initialize the textures
	void initVariables(); // Function to initialize the variables

	Texture2D texture; // Variable to store the sprite sheet to be animated
	Rectangle source; // Variable to store the updated sprite sheet

	// Variables to animate the sprite
	int currentFrame, maxFrame;
	float currentTime, frameTime;

	void unload(); // memory management function
};