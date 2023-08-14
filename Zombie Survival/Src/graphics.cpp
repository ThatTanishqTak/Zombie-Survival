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

	score = 0; // Initialize the score

	// Initialize the timer
	elapsedTime = 0.0f;
	dayTime = 150.0f;
	nightTime = 240.0f;

	gameState = GameState::Night; // Set the starting time to night
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
	float deltaTime = GetFrameTime();
	elapsedTime += deltaTime;

}

void Graphics::render()
{
	// Render the UI
	if (gameState == GameState::Night)
		DrawTexture(backgroundNight, 0, 0, WHITE);
	else
		DrawTexture(backgroundDay, 0, 0, WHITE);

	DrawText(("Score:" + std::to_string(score)).c_str(), 905, 0, 24, RED); // Render the score
}

void Graphics::unload()
{
	// Unload all the textures
	UnloadTexture(backgroundDay);
	UnloadTexture(backgroundNight);
}