//// This file contains the definations of all the member variables and methods in the "player.h"

#include "player.h"

Player::Player()
{
	// Call the initialization functions
	initTextures();
	initVariables();
}

Player::~Player()
{
	// Call the memory management function
	unload();
}

void Player::initTextures()
{
	// Initialize the player textures
	playerIdle = LoadTexture("Textures/Player/playerIdle.png");
	playerRun = LoadTexture("Textures/Player/playerRun.png");
	playerJump = LoadTexture("Textures/Player/playerJump.png");
	playerAttack = LoadTexture("Textures/Player/playerAttack.png");
	playerHurt = LoadTexture("Textures/Player/playerHurt.png");
	playerDead = LoadTexture("Textures/Player/playerDead.png");
}

void Player::initVariables()
{
	// Initialize the player variables
	playerPos = { 512.0f,600.0f - playerIdle.height };
	moveSpeed = 100.0f;
	deltaTime = GetFrameTime();
}

void Player::update()
{
	// Update the player

	// Player movement
	if (IsKeyDown(KEY_D))
		playerPos.x += moveSpeed * GetFrameTime();
	if (IsKeyDown(KEY_A))
		playerPos.x -= moveSpeed * GetFrameTime();

	// Check collision
	if (playerPos.x <= 0.0f)
		playerPos.x = 0.0f;
	if (playerPos.x + playerIdle.width / 6.0f >= 1024.0f)
		playerPos.x = 1024.0f - playerIdle.width / 6.0f;
}

void Player::render()
{
	// Render the player
	
	// Renders moving right
	if (IsKeyDown(KEY_D))
		DrawTexturePro(playerRun, { 0.0f, 0.0f, playerRun.width / 6.0f, static_cast<float>(playerRun.height) }, 
			{ playerPos.x, playerPos.y, playerRun.width / 6.0f, static_cast<float>(playerRun.height) }, 
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Renders moving left
	else if (IsKeyDown(KEY_A))
		DrawTexturePro(playerRun, { 0.0f, 0.0f, -playerRun.width / 6.0f, static_cast<float>(playerRun.height) },
			{ playerPos.x, playerPos.y, playerRun.width / 6.0f, static_cast<float>(playerRun.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Render attack right
	
	// Render attack left 
	
	// Renders idle
	else
		DrawTexturePro(playerIdle, { 0.0f, 0.0f, playerIdle.width / 4.0f, static_cast<float>(playerIdle.height) },
			{ playerPos.x, playerPos.y, playerIdle.width / 4.0f, static_cast<float>(playerIdle.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
}

void Player::unload()
{
	// Unload all the textures
	UnloadTexture(playerIdle);
	UnloadTexture(playerRun);
	UnloadTexture(playerJump);
	UnloadTexture(playerAttack);
	UnloadTexture(playerHurt);
	UnloadTexture(playerDead);
}