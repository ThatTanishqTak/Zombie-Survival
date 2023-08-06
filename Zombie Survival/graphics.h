// This file contains all the declartions for the member variables and methods for the UI

#pragma once // Make sure that the include happens only once

#include <sstream>
#include "raylib.h"

enum class TimeState { Day, Night }; // Create an enum to handle the switch between day and night

class Graphics // This class will handle the UI
{
public:
	Graphics(); // Constructor
	~Graphics(); // Destructor

	// Define the variables to store the background textures
	Texture2D backgroundDay;
	Texture2D backgroundNight;

	void initVariables(); // Function to initialize the variables
	void initTextures(); // Function to initialize the textures

	void update(); // Function to switch between the backgrounds
	void render(); // Function to render the different backgrounds

private:
	void unload(); // Function to handle memory management
};