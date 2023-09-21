#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"
#include "globals.h"

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

	Image backgroundDay;
	Image backgroundNight;
	Texture texture;
	GameTime gameTime;
};

#endif