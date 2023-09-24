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
	
	Texture texture;
	Texture playerIdle;
	Texture playerRun;
	Texture playerAttack;
	Texture playerHurt;
	Texture playerDead;

	Rectangle source;
	Rectangle destination;

	int updateAnimations(int maxFrame);
	int attack(int hitPoints);
};

#endif