#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "globals.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	virtual void update();
	virtual void render();

private:
	Vector2 playerPos;
	
	Texture texture;
	Texture playerIdle;
	Texture playerRun;
	Texture playerAttack;
	Texture playerHurt;
	Texture playerDead;

	Rectangle source;
	Rectangle destination;
};

#endif