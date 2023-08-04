// This files contains the definations for the methods in "graphics.h"

#include "graphics.h"

Graphics::Graphics()
{
	// Constructors
	initVariables();
	initTextures();
}

Graphics::~Graphics()
{
	// Destructors
	unload();
}

void Graphics::initVariables()
{
	
}

void Graphics::initTextures()
{
	backgroundDay = LoadTexture("Textures/Backgrounds/DayTime.png");
	backgroundNight = LoadTexture("Textures/Backgrounds/NightTime.png");
}

void Graphics::update()
{

}

void Graphics::render()
{
	DrawTexture(backgroundDay, 0, 0, WHITE);
}

void Graphics::unload()
{
	UnloadTexture(backgroundDay);
	UnloadTexture(backgroundNight);
}