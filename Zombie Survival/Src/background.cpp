#include "background.h"

Background::Background()
{
	gameObjects.push_back(this);

	backgroundDay = LoadImage("Textures/Backgrounds/DayTime.png");
	backgroundNight = LoadImage("Textures/Backgrounds/NightTime.png");

	gameTime = GameTime::DAY;
	texture = LoadTextureFromImage(backgroundDay);
}

Background::~Background() { UnloadTexture(texture); }

void Background::update()
{
}

void Background::render() { DrawTexture(texture, 0, 0, WHITE); }
