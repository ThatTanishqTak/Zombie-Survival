#ifndef ENEMY_H
#define ENEMY_H

#include "globals.h"
#include "raylib.h"

class Enemy : public GameObject
{
public:
	Enemy();
	~Enemy();

	virtual void update();
	virtual void render();

private:
	Vector2 enemyPos;

	Texture2D texture;

	Rectangle source;
	Rectangle destination;
};

#endif