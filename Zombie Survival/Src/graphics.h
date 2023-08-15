// This file contains all the declartions for the member variables and methods for the UI

#pragma once // Make sure that the include happens only once

#include <sstream>
#include <iomanip>
#include "raylib.h"

enum class GameState { DAY, NIGHT }; // Create an enum to handle the switch between day and night

class Graphics // This class will handle the UI
{
public:
	Graphics(); // Constructor
	~Graphics(); // Destructor

	// Define the variables to store the background textures
	Texture2D backgroundDay;
	Texture2D backgroundNight;

	GameState gameState; // Variable of "GameState" type to store the current state of the game

	float elapsedTime, dayTime, nightTime; // Variables to store the time

	int score; // Variable to store the score

	int level; // Variable to store the current level

	void update(); // Function to switch between the backgrounds
	void render(); // Function to render the different backgrounds

private:
	void initVariables(); // Function to initialize the variables
	void initTextures(); // Function to initialize the textures

	std::string FormatTime(float timeInSeconds); // Declare the "FormatTime" function

	void unload(); // Function to handle memory management
};