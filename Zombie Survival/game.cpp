// This file contains the definations of all the methods in "game.h"

#include "game.h"

Game::Game()
{
	grp_obj = new Graphics();

	// Functions that are needed at the start of the game
	initVariables();
	initScreen();
}

Game::~Game()
{
	// Clear the memory
	unload();
	CloseWindow();
}

void Game::run()
{
	// Main game loop
	while (!WindowShouldClose())
	{
		update();
		render();
	}
}


void Game::initVariables()
{
	// Define dimensions
	windowWidth = 1024;
	windowHeight = 600;
}


void Game::initScreen()
{
	// Starts the window
	InitWindow(windowWidth, windowHeight, "Zombie Survival");
	SetTargetFPS(60);
}

void Game::update()
{
	// Update the game
}

void Game::render()
{
	BeginDrawing();
	ClearBackground(BLACK);

	// Render everything here
	grp_obj->render();

	EndDrawing();
}

void Game::unload()
{
	// Memory management
	delete grp_obj;
}