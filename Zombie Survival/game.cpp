// This file contains the definations of all the methods in "game.h"

#include "game.h"

Game::Game(Graphics* graphics)
{
	// Functions that are needed at the start
	grp_obj = graphics;

	initTextures();
	initVariables();
	initScreen();
}

Game::~Game()
{
	// Clear the memory
	unload();

	delete grp_obj;

	CloseWindow();
}

void Game::run()
{
	// Runs the game
	while (!WindowShouldClose())
	{
		update();
		render();
	}
}


void Game::initVariables()
{
	// Set window Dimensions
	windowWidth = 1024;
	windowHeight = 600;

	grp_obj->initVariables();
}


void Game::initScreen()
{
	// Starts the window
	InitWindow(windowWidth, windowHeight, "Zombie Survival");
	SetTargetFPS(60);
}


void Game::initTextures()
{
	// Initialize the textures
	grp_obj->initTextures();
}

void Game::update()
{
	// Update the game
	grp_obj->update();
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
	// Unload the textures
}