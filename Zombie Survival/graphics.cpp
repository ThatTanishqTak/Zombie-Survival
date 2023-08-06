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
	// Initialize the UI textures
	backgroundDay = LoadTexture("Textures/Backgrounds/DayTime.png");
	backgroundNight = LoadTexture("Textures/Backgrounds/NightTime.png");
}

void Graphics::update()
{
	// Update graphics
}

void Graphics::render()
{
	// Render the UI
	DrawTexture(backgroundDay, 0, 0, WHITE);
}

void Graphics::unload()
{
	// Unload all the textures
	UnloadTexture(backgroundDay);
	UnloadTexture(backgroundNight);
}