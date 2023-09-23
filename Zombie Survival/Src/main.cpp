#include "raylib.h"
#include "globals.h"
#include "gameobjects.h"
#include "background.h"
#include "player.h"

int main()
{
	const int windowWidth = 1024;
	const int windowHeight = 600;

	InitWindow(windowWidth, windowHeight, "Zombie Survival");
	SetTargetFPS(60);

	Background background;
	Player player;

	while (!WindowShouldClose())
	{
		for (GameObject* gameObjects : gameObjects) { gameObjects->update(); }

		BeginDrawing();
		ClearBackground(BLACK);

		for (GameObject* gameObjects : gameObjects) { gameObjects->render(); }

		EndDrawing();
	}

	CloseWindow();

	return 0;
}