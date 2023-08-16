// This file contains the definations of all the methods in "game.h"

#include "game.h"

Game::Game()
{
	// Functions that are needed at the start of the game
	initVariables();
	initScreen();
	
	// Allocate memory to the objects
	grp_obj = new Graphics();
	ply_obj = new Player();
	eny_obj = new Enemy();
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
	// Define window dimensions
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
	grp_obj->update();
	ply_obj->update();
	eny_obj->update();
}

void Game::render()
{
	BeginDrawing();
	ClearBackground(BLACK);

	// Render everything here
	grp_obj->render();
	ply_obj->render();
	//eny_obj->render();

	EndDrawing();
}

void Game::unload()
{
	// Clear up the memory
	delete grp_obj;
	delete ply_obj;
	delete eny_obj;
}