#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"
#include "globals.h"
#include <iostream>

class Player : public GameObject
{
public:
	Player();
	~Player();

	virtual void update();
	virtual void render();

private:
	int direction;

	Vector2 playerPos;
	Rectangle source;
	
	Texture2D playerIdle;
	Texture2D playerRun;
	Texture2D playerAttack;
	Texture2D playerHurt;
	Texture2D playerDead;

	int updateAnimations(int maxFrame);
};

#endif