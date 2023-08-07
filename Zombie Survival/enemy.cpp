// This file contains the definations of all the member variables and methods in "enemy.h"

#include "enemy.h"

Enemy::Enemy()
{
	initTextures();
	initVariables();
}

Enemy::~Enemy()
{
	unload();
}

void Enemy::update()
{

}

void Enemy::render()
{

}

void Enemy::initTextures()
{
	enemyIdle = LoadTexture("Textures/Enemy/enemyIdle.png");
	enemyRun = LoadTexture("Textures/Enemy/enemyRun.png");
	enemyJump = LoadTexture("Textures/Enemy/enemyJump.png");
	enemyAttack = LoadTexture("Textures/Enemy/enemyAttack.png");
	enemyHurt = LoadTexture("Textures/Enemy/enemyHurt.png");
	enemyDead = LoadTexture("Textures/Enemy/enemyDead.png");
}

void Enemy::initVariables()
{

}

void Enemy::unload()
{
	UnloadTexture(enemyIdle);
	UnloadTexture(enemyRun);
	UnloadTexture(enemyJump);
	UnloadTexture(enemyAttack);
	UnloadTexture(enemyHurt);
	UnloadTexture(enemyDead);
}