// This files contains the definations for the methods in "graphics.h"

#include "graphics.h"

Graphics::Graphics()
{
	// Call the initialization functions
	initVariables();
	initTextures();
}

Graphics::~Graphics()
{
	// Call the memory management function
	unload();
}

void Graphics::initVariables()
{
	// Initialize the variables
}

void Graphics::initTextures()
{
	// Initialize the textures
	backgroundDay = LoadTexture("Textures/Backgrounds/DayTime.png");
	backgroundNight = LoadTexture("Textures/Backgrounds/NightTime.png");
}

void Graphics::update()
{
	// Update graphics
}

void Graphics::render()
{
	// Render graphics
	DrawTexture(backgroundDay, 0, 0, WHITE);
}

void Graphics::unload()
{
	// Perform memory management
	UnloadTexture(backgroundDay);
	UnloadTexture(backgroundNight);
}