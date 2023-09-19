#include "raylib.h"

int main()
{
	const int windowWidth = 1080;
	const int windowHeight = 600;

	InitWindow(windowWidth, windowHeight, "Zombie Survival");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}