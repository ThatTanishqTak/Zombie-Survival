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

	gameState = GameState::DAY; // Set the starting time to night

	score = 0; // Initialize the score
	level = 1; // Initialize the level

	// Initialize the timer
	elapsedTime = 0.0f;
	dayTime = 150.0f; // 2:30min
	nightTime = 240.0f; // 4:00min
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

	// Day
	if (gameState == GameState::DAY)
	{
		dayTime -= GetFrameTime();
		if (dayTime <= 0)
		{
			dayTime = 150.0f;
			gameState = GameState::NIGHT;
		}
	}
	// Night
	else if (gameState == GameState::NIGHT)
	{
		nightTime -= GetFrameTime();
		if (nightTime <= 0)
		{
			level++;
			nightTime = 240.0f;
			gameState = GameState::DAY;
		}
	}
}

void Graphics::render()
{
	// Render the UI

	// Renders the current game state 
	if (gameState == GameState::DAY)
	{
		DrawTexture(backgroundDay, 0, 0, WHITE); // Render day background
		DrawText(("Time Till Night: " + FormatTime(dayTime)).c_str(), 5, 0, 20, RED); // Render the timer in day
	}
	else if (gameState == GameState::NIGHT)
	{
		DrawTexture(backgroundNight, 0, 0, WHITE); // Render night background
		DrawText(("Time Till Day: " + FormatTime(nightTime)).c_str(), 5, 0, 20, RED); // Render the timer in night
	}

	DrawText(("Score: " + std::to_string(score)).c_str(), 905, 0, 22, RED); // Render the score
	DrawText(("Level: " + std::to_string(level)).c_str(), 905, 20, 22, RED); // Render the current level

	DrawRectangle(5, 25, 100, 15, GREEN); // Health bar
	DrawRectangle(5, 45, 100, 15, BLUE); // Energy bar
}

std::string Graphics::FormatTime(float timeInSeconds)
{
	// Get minutes and seconds
	int minutes = (int)timeInSeconds / 60;
	int seconds = (int)timeInSeconds % 60;

	// Format the time as XX:XX
	std::ostringstream formattedTime;
	formattedTime << std::setw(2) << std::setfill('0') << minutes << ":"
		<< std::setw(2) << seconds;

	return formattedTime.str(); // Return the formated time
}

void Graphics::unload()
{
	// Unload all the textures
	UnloadTexture(backgroundDay);
	UnloadTexture(backgroundNight);
}