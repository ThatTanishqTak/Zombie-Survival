// This file contains the definations of all the methods in "game.h"

#include "game.h"

Game::Game()
{
	// Functions that are needed at the start
	initVariables();
	initTextures();
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
	windowWidth = 1080;
	windowHeight = 720;
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

	EndDrawing();
}

void Game::unload()
{
	// Unload the textures
}