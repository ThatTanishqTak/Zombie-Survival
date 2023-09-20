#include "globals.h"
#include "raylib.h"
#include "gameobjects.h"
#include "background.h"
#include "player.h"

int main()
{
	// Define window dimensions
	const int windowWidth = 1024;
	const int windowHeight = 600;

	// Initialize the window
	InitWindow(windowWidth, windowHeight, "Zombie Survival");
	SetTargetFPS(60);

	// Insatiate the objects
	Background background;
	Player player;

	// Main game loop
	while (!WindowShouldClose())
	{
		for (GameObject* gameObjects : gameObjects) { gameObjects->update(); } // Update everything here

		BeginDrawing();
		ClearBackground(BLACK);

		for (GameObject* gameObjects : gameObjects) { gameObjects->render(); } // Render everything here

		EndDrawing();
	}

	CloseWindow(); // De-initialize the window

	return 0; // Exit code
}