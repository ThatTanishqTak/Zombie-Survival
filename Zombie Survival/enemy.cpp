// This file contains the definations of all the member variables and methods in "enemy.h"

#include "enemy.h"

Enemy::Enemy()
{
	// Call the initialization functions
	initTextures();
	initVariables();
}

Enemy::~Enemy()
{
	// Call the memory management function
	unload();
}

void Enemy::update()
{
	// Update the enemy
}

void Enemy::render()
{
	// Render the enemy
}

void Enemy::initTextures()
{
	// Initialize the enemy textures
	enemyIdle = LoadTexture("Textures/Enemy/enemyIdle.png");
	enemyRun = LoadTexture("Textures/Enemy/enemyRun.png");
	enemyJump = LoadTexture("Textures/Enemy/enemyJump.png");
	enemyAttack = LoadTexture("Textures/Enemy/enemyAttack.png");
	enemyHurt = LoadTexture("Textures/Enemy/enemyHurt.png");
	enemyDead = LoadTexture("Textures/Enemy/enemyDead.png");
}

void Enemy::initVariables()
{
	// Initialize the enemy variables
}

void Enemy::unload()
{
	// Unload all the textures
	UnloadTexture(enemyIdle);
	UnloadTexture(enemyRun);
	UnloadTexture(enemyJump);
	UnloadTexture(enemyAttack);
	UnloadTexture(enemyHurt);
	UnloadTexture(enemyDead);
}