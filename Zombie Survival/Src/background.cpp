#include "background.h"
#include <string>

Background::Background()
{
	gameObjects.push_back(this);

	backgroundDay = LoadTexture("Textures/Backgrounds/DayTime.png");
	backgroundNight = LoadTexture("Textures/Backgrounds/NightTime.png");

	gameTime = GameTime::NIGHT;

	elapsedTime = 0.0f;
	dayTime = 150.0f;
	nightTime = 240.0f;

	score = 0;
	level = 1;
}

Background::~Background()
{ 
	UnloadTexture(backgroundDay); 
	UnloadTexture(backgroundNight); 
}

void Background::update()
{
	if (gameTime == GameTime::DAY)
	{
		dayTime -= GetFrameTime();
		if (dayTime <= 0)
		{
			dayTime = 150.0f;
			gameTime = GameTime::NIGHT;
		}
	}
	else if (gameTime == GameTime::NIGHT)
	{
		nightTime -= GetFrameTime();
		if (nightTime <= 0)
		{
			level++;
			nightTime = 240.0f;
			gameTime = GameTime::DAY;
		}
	}
}

void Background::render() 
{ 
	if (gameTime == GameTime::DAY)
	{
		DrawTexture(backgroundDay, 0, 0, WHITE);
		DrawText(("Time Till Night: " + FormatTime(dayTime)).c_str(), 5, 0, 20, RED);
	}
	else if (gameTime == GameTime::NIGHT)
	{
		DrawTexture(backgroundNight, 0, 0, WHITE);
		DrawText(("Time Till Day: " + FormatTime(nightTime)).c_str(), 5, 0, 20, RED);
	}

	DrawText(("Score: " + std::to_string(score)).c_str(), 905, 0, 22, RED);
	DrawText(("Level: " + std::to_string(level)).c_str(), 905, 20, 22, RED);

	if (!isAlive) { DrawText("DEAD!", windowWidth / 2, windowHeight / 2, 32, RED); }
}

std::string Background::FormatTime(float timeInSeconds)
{
	int minutes = (int)timeInSeconds / 60;
	int seconds = (int)timeInSeconds % 60;

	std::ostringstream formattedTime;
	formattedTime << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << seconds;

	return formattedTime.str();
}