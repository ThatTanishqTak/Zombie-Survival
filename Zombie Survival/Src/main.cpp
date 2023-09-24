#include "raylib.h"
#include "globals.h"
#include "gameobjects.h"
#include "background.h"
#include "player.h"
#include "enemy.h"

int main()
{
	InitWindow(windowWidth, windowHeight, "Zombie Survival");
	SetTargetFPS(60);

	Background background;
	Player player;
	Enemy enemy;

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