#include "player.h"

Player::Player()
{
	gameObjects.push_back(this);

	texture = LoadTexture("Textures/Player/playerIdle.png");
	playerIdle = LoadTexture("Textures/Player/playerIdle.png");
	playerRun = LoadTexture("Textures/Player/playerRun.png");
	playerAttack = LoadTexture("Textures/Player/playerAttack.png");
	playerHurt = LoadTexture("Textures/Player/playerHurt.png");
	playerDead = LoadTexture("Textures/Player/playerDead.png");

	playerPos = { 512.0f, static_cast<float>(GetScreenHeight() - texture.height) };

	source = { 0, 0, direction * texture.width / 6.0f, static_cast<float>(texture.height) };
	destination = { playerPos.x, playerPos.y, texture.width / 6.0f, static_cast<float>(texture.height) };
}

Player::~Player() { UnloadTexture(texture); }

void Player::update()
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) 
	{
		direction = -1;
		playerPos.x -= speed * GetFrameTime(); 
	}
	if (IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))
	{
		direction = 1;
		playerPos.x += speed * GetFrameTime();
	}
	destination.x = playerPos.x;

	if (playerPos.x <= 0) { playerPos.x = 0; }
	if (playerPos.x + texture.width / 6.0f >= 1024) { playerPos.x = 1024 - texture.width / 6.0f; }
}

void Player::render()
{
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D)) { DrawTexturePro(playerRun, { 0, 0, direction * texture.width / 6.0f, 
										static_cast<float>(texture.height) }, destination, { 0, 0 }, 0.0f, WHITE); }

	else { DrawTexturePro(texture, { 0, 0, direction * texture.width / 6.0f, static_cast<float>(texture.height) }, 
								   destination, { 0, 0 }, 0.0f, WHITE); }
}
