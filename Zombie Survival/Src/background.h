#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"
#include "globals.h"
#include <sstream>
#include <iomanip>

enum GameTime { DAY, NIGHT };

class Background : public GameObject
{
public:
	Background();
	~Background();

	virtual void update();
	virtual void render();

private:
	int score;

	Texture2D backgroundDay;
	Texture2D backgroundNight;
	GameTime gameTime;

	std::string FormatTime(float timeInSeconds);
};

#endif