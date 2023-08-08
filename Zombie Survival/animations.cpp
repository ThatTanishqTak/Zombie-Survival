// This file is the animation manager

#include "animations.h"

Animations::Animations(Texture2D texture, int rowFrame, int columnFrame, int framePerSecond)
{
	anim_ply_obj = new Player(); // Allocate memory to the object

	// Call the initialization functions
	initTextures();
	initVariables();
}

Animations::~Animations()
{
	// Perform memory management
	unload();
}

void Animations::initTextures()
{
	// Initialize textures
}

void Animations::initVariables()
{
	// Initialize variables
	currentTime = 0.0f;
	currentFrame = 0;
}

void Animations::update()
{
	// Update the animations
	currentTime += GetFrameTime();
	if (currentTime >= frameTime)
	{
		currentTime = currentTime + 1 % maxFrame;
		currentTime = 0.0f;
	}
}

void Animations::render(float x, float y)
{
	// Render the animations
}

void Animations::unload()
{
	// Unload the texture
	UnloadTexture(texture);

	delete anim_ply_obj; // Clear up the memory
}