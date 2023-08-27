// This file contains all the member variables and methods that handles the enemy

#pragma once // Make sure that include happens only once

#include "raylib.h"
#include "raymath.h"
#include "player.h"

enum class EnemyState {enemyRun, enemyAttack, enemyHurt, enemyDead};

class Enemy // This class will handle the enemy
{
public:
	Enemy(); // Constructor
	~Enemy(); // Destructor

	void update(); // Function to update the enemy
	void render(); // Function to render the enemy

private:
	Player* ply_emy_obj; // Creating the player object for the enemy class

	void initTextures(); // Function to initialize the textures
	void initVariables(); // Function to initialize the variables

	EnemyState enemyState; // Declare the enemy state

	float moveSpeed; // Declare the enemy speed
	
	// Define enemy variables
	int maxEnemy;
	bool isAlive;

	Vector2 enemyPos; // Set enemy position
	Rectangle enemyHitBox; // The enemy hitbox

	Vector2 toTarget; // Vector to get the distance between the enemy and the player

	// Variables to store the enemy textures
	Texture2D enemyRun;
	Texture2D enemyAttack;
	Texture2D enemyHurt;
	Texture2D enemyDead;

	// Variables for animations
	int currentFrame;
	float runningTime, updateTime;

	int updateAnimations(int maxFrame); // Function to update the enemy animations

	void spawnEnemy(); // Function responsible to spawn enemies
	void unload(); // Function to handle memory management
};