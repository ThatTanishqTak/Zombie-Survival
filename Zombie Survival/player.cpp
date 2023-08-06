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
}

void Player::update()
{
	// Update the player
}

void Player::render()
{
	// Render the player
	DrawTexturePro(playerIdle, { 0.0f, 0.0f, playerIdle.width / 6.0f, (float)playerIdle.height },
		{ 0.0f, 600.0f - (float)playerIdle.height, playerIdle.width / 6.0f, (float)playerIdle.height },
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