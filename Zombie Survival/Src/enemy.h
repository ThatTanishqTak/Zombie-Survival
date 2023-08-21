// This file contains all the member variables and methods that handles the enemy

#pragma once // Make sure that include happens only once

#include "raylib.h"

class Enemy // This class will handle the enemy
{
public:
	Enemy(); // Constructor
	~Enemy(); // Destructor

	void update(); // Function to update the enemy
	void render(); // Function to render the enemy

private:
	void initTextures(); // Function to initialize the textures
	void initVariables(); // Function to initialize the variables

	int updateAnimations(int maxFrame); // Function to update the enemy animations
	
	// Define enemy variables
	int maxEnemy;
	bool isAlive;

	Vector2 enemyPos; // Set enemy position
	Rectangle enemyHitBox; // The enemy hitbox

	// Variables to store the enemy textures
	Texture2D enemyRun;
	Texture2D enemyAttack;
	Texture2D enemyHurt;
	Texture2D enemyDead;

	// Variables for animations
	int currentFrame;
	float runningTime, updateTime;

	void unload(); // Function to handle memory management
};