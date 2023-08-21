// This file contains the definations of all the member variables and methods in "enemy.h"

#include "enemy.h"

Enemy::Enemy()
{
	// Call the initialization functions
	initTextures();
	initVariables();
}

Enemy::~Enemy() { unload(); } // Call the memory management function

void Enemy::update()
{
	// Update the enemy
}

void Enemy::render()
{
	// Render the enemy
	DrawTexturePro(enemyIdle, { enemyIdle.width / 8.0f * updateAnimations(8), 0.0f,
		enemyIdle.width / 8.0f, static_cast<float>(enemyIdle.height)},
		{ 512.0f, 600.0f - enemyIdle.height, enemyIdle.width / 8.0f, static_cast<float>(enemyIdle.height) },
		{ 0.0f,0.0f }, 0.0f, WHITE);
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
	enemyPos = { 100.0f,600.0f - enemyIdle.height };
	enemyHitBox = { enemyPos.x, enemyPos.y, static_cast<float>(enemyIdle.width), static_cast<float>(enemyIdle.height) };

	// Initialize animations variables
	currentFrame = 0;
	updateTime = 1.0f / 12.0f;
	runningTime = 0.0f;
}

int Enemy::updateAnimations(int maxFrame)
{
	// Functionality to update the current frames
	runningTime += GetFrameTime(); // Delta time
	if (runningTime >= updateTime)
	{
		currentFrame++;
		runningTime = 0.0f;
		if (currentFrame > maxFrame) currentFrame = 0;
	}

	return currentFrame; // return the updated frame
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