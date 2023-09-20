#ifndef PLAYER_H
#define PLAYER_H

#include "globals.h"
#include "raylib.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	virtual void update();
	virtual void render();

private:
	Texture texture;
	Vector2 playerPos;
	Rectangle source;
	Rectangle destination;
};

#endif