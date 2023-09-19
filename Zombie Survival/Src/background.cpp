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
	// GameTime = DAY
	if (gameTime == GameTime::DAY) { texture = LoadTextureFromImage(backgroundDay); }
	// GameTime = NIGHT
	if (gameTime == GameTime::NIGHT) { texture = LoadTextureFromImage(backgroundNight); }
}

void Background::render() { DrawTexture(texture, 0, 0, WHITE); }
