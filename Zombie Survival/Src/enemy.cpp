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

	if (enemyState == EnemyState::enemyRun)
	{
		// Update the run state
	}
	if (enemyState == EnemyState::enemyAttack)
	{
		// Update the attack state
	}
	if (enemyState == EnemyState::enemyHurt)
	{
		// Update the hurt state
	}
	if (enemyState == EnemyState::enemyDead)
	{
		// Update the dead state
	}
}

void Enemy::render()
{
	// Render the enemy
	DrawTexturePro(enemyRun, { enemyRun.width / 7.0f * updateAnimations(7), 0.0f,
		enemyRun.width / 7.0f, static_cast<float>(enemyRun.height)},
		{ 512.0f, 600.0f - enemyRun.height, enemyRun.width / 7.0f, static_cast<float>(enemyRun.height) },
		{ 0.0f,0.0f }, 0.0f, WHITE);
}

void Enemy::initTextures()
{
	// Initialize the enemy textures
	enemyRun = LoadTexture("Textures/Enemy/enemyRun.png");
	enemyAttack = LoadTexture("Textures/Enemy/enemyAttack.png");
	enemyHurt = LoadTexture("Textures/Enemy/enemyHurt.png");
	enemyDead = LoadTexture("Textures/Enemy/enemyDead.png");
}

void Enemy::initVariables()
{
	// Initialize enemy variables
	maxEnemy = 1;
	isAlive = true;

	// Initialize the enemy variables
	enemyPos = { 100.0f,600.0f - enemyRun.height };
	enemyHitBox = { enemyPos.x, enemyPos.y, static_cast<float>(enemyRun.width), static_cast<float>(enemyRun.height) };

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

void Enemy::spawnEnemy()
{
	// Spawn enemy here
}

void Enemy::unload()
{
	// Unload all the textures
	UnloadTexture(enemyRun);
	UnloadTexture(enemyAttack);
	UnloadTexture(enemyHurt);
	UnloadTexture(enemyDead);
}