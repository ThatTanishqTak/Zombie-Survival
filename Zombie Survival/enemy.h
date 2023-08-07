// This file contains all the member variables and methods that handles the enemy

#pragma once

#include "raylib.h"

class Enemy
{
public:
	Enemy();
	~Enemy();

	void update();
	void render();

private:
	void initTextures();
	void initVariables();

	Texture2D enemyIdle;
	Texture2D enemyRun;
	Texture2D enemyJump;
	Texture2D enemyAttack;
	Texture2D enemyHurt;
	Texture2D enemyDead;

	void unload();
};