#include "background.h"
#include <string>

Background::Background()
{
	gameObjects.push_back(this);

	backgroundDay = LoadImage("Textures/Backgrounds/DayTime.png");
	backgroundNight = LoadImage("Textures/Backgrounds/NightTime.png");

	gameTime = GameTime::DAY;
	texture = LoadTextureFromImage(backgroundDay);

	score = 0;
}

Background::~Background() { UnloadTexture(texture); }

void Background::update()
{
}

void Background::render() 
{ 
	DrawTexture(texture, 0, 0, WHITE);
	DrawText((("Score: " + std::to_string(score)).c_str()), GetScreenWidth() - 125, 0, 24, RED);
}
