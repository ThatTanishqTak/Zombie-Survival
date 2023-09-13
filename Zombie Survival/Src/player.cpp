// This file contains the definations of all the member variables and methods in "player.h"

#include "player.h"

Player::Player()
{
	// Call the initialization functions
	initTextures();
	initVariables();
}

Player::~Player() { unload(); } // Call the memory management function

void Player::initTextures()
{
	// Initialize the player textures
	playerIdle = LoadTexture("Textures/Player/playerIdle.png");
	playerRun = LoadTexture("Textures/Player/playerRun.png");
	playerAttack = LoadTexture("Textures/Player/playerAttack.png");
	playerHurt = LoadTexture("Textures/Player/playerHurt.png");
	playerDead = LoadTexture("Textures/Player/playerDead.png");
}

void Player::initVariables()
{
	playerPos = { 512.0f,600.0f - playerIdle.height }; // Initialize the player position
	moveSpeed = 100.0f; // Initialize the player movement variables
	
	// Initialize animations variables
	currentFrame = 0;
	updateTime = 1.0f / 12.0f;
	runningTime = 0.0f;

	changeDirection = 1; // variable to store the change in direction
}

int Player::updateAnimations(int maxFrame) // Local variable so that same function can be used for multiple sprite sheets
{
	// Functionality to update the current frames
	runningTime += GetFrameTime(); // Delta time
	if (runningTime >= updateTime)
	{
		currentFrame++;
		runningTime = 0.0f;
		if (currentFrame > maxFrame) { currentFrame = 0; }
	}

	return currentFrame; // return the updated frame
}

void Player::update()
{
	// Player movement
	if (IsKeyDown(KEY_D)) 
	{ 
		playerPos.x += moveSpeed * GetFrameTime(); 
		changeDirection = 1;
	}
	if (IsKeyDown(KEY_A)) 
	{ 
		playerPos.x -= moveSpeed * GetFrameTime();
		changeDirection = -1;
	}

	//player attack

	// Check collision
	if (playerPos.x <= 0.0f) { playerPos.x = 0.0f; }
	if (playerPos.x + playerIdle.width / 6.0f >= 1024.0f) { playerPos.x = 1024.0f - playerIdle.width / 6.0f; }
}

void Player::render()
{
	// Render the player
	
	// Renders running
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_A))
		DrawTexturePro(playerRun, { (playerRun.width * changeDirection) / 6.0f * updateAnimations(6), 0.0f,
			(playerRun.width * changeDirection) / 6.0f, static_cast<float>(playerRun.height) },
			{ playerPos.x, playerPos.y, playerRun.width / 6.0f, static_cast<float>(playerRun.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Renders attacking
	else if (IsKeyDown(KEY_K))
		DrawTexturePro(playerAttack, { (playerAttack.width * changeDirection) / 6.0f * updateAnimations(6), 0.0f,
			(playerAttack.width * changeDirection) / 6.0f, static_cast<float>(playerAttack.height) },
			{ playerPos.x, playerPos.y, playerAttack.width / 6.0f, static_cast<float>(playerAttack.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Renders idle
	else
		DrawTexturePro(playerIdle, { (playerIdle.width * changeDirection) / 4.0f * updateAnimations(4), 0.0f,
			(playerIdle.width * changeDirection) / 4.0f, static_cast<float>(playerIdle.height) },
			{ playerPos.x, playerPos.y, playerIdle.width / 4.0f, static_cast<float>(playerIdle.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
}

void Player::unload()
{
	// Unload all the textures
	UnloadTexture(playerIdle);
	UnloadTexture(playerRun);
	UnloadTexture(playerAttack);
	UnloadTexture(playerHurt);
	UnloadTexture(playerDead);
} 