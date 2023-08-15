// This file contains the definations of all the member variables and methods in "player.h"

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
	// Initialize the player movement variables
	playerPos = { 512.0f,600.0f - playerIdle.height };
	moveSpeed = 100.0f;
	jumpForce = 4500.0f;

	gravity = 200.0f; // Initialize gravity
	isOnGround = true; // Turn gravity on
	
	// Initialize animations variables
	currentFrame = 0;
	updateTime = 1.0f / 12.0f;
	runningTime = 0.0f;
}

void Player::update()
{
	// Player movement
	if (IsKeyDown(KEY_D))
		playerPos.x += moveSpeed * GetFrameTime();
	if (IsKeyDown(KEY_A))
		playerPos.x -= moveSpeed * GetFrameTime();

	// Player jump
	if (IsKeyDown(KEY_SPACE) && isOnGround)
	{
		playerPos.y -= jumpForce * GetFrameTime();
		isOnGround = false;
	}
	if (!isOnGround) // Make sure that player can only jump once
		playerPos.y += gravity * GetFrameTime();

	// Check collision
	if (playerPos.x <= 0.0f)
		playerPos.x = 0.0f;
	if (playerPos.x + playerIdle.width / 6.0f >= 1024.0f)
		playerPos.x = 1024.0f - playerIdle.width / 6.0f;

	if (playerPos.y + playerIdle.height >= 600.0f) // Make ground check and letting player jump again
	{
		playerPos.y = 600.0f - playerIdle.height;
		isOnGround = true;
	}
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
			{ playerPos.x - playerRun.width / 12.0f, playerPos.y, playerRun.width / 6.0f, static_cast<float>(playerRun.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Renders attack right
	else if (IsKeyDown(KEY_L))
		DrawTexturePro(playerAttack, { 0.0f, 0.0f, playerAttack.width / 6.0f, static_cast<float>(playerAttack.height) },
			{ playerPos.x, playerPos.y, playerAttack.width / 6.0f, static_cast<float>(playerAttack.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Renders attack left
	else if (IsKeyDown(KEY_J))
		DrawTexturePro(playerAttack, { 0.0f, 0.0f, -playerAttack.width / 6.0f, static_cast<float>(playerAttack.height) },
			{ playerPos.x - playerAttack.width / 12.0f, playerPos.y, playerAttack.width / 6.0f, static_cast<float>(playerAttack.height) },
			{ 0.0f,0.0f }, 0.0f, WHITE);
	// Render jump
	else if (IsKeyDown(KEY_SPACE))
		DrawTexturePro(playerJump, { 0.0f, 0.0f, playerJump.width / 4.0f, static_cast<float>(playerJump.height) },
			{ playerPos.x, playerPos.y, playerJump.width / 4.0f, static_cast<float>(playerJump.height) },
			{ 0.0f, 0.0f }, 0.0f, WHITE);
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