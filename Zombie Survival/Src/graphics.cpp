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
	score = 0;
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
	DrawTexture(backgroundNight, 0, 0, WHITE);

	DrawText(("Score: " + std::to_string(score)).c_str(), 920, 0, 24, RED); // Render the score
}

void Graphics::unload()
{
	// Unload all the textures
	UnloadTexture(backgroundDay);
	UnloadTexture(backgroundNight);
}