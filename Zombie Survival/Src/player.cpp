#include "player.h"

Player::Player()
{
	gameObjects.push_back(this);

	Image playerInage = LoadImage("Textures/Player/playerIdle.png");
	texture = LoadTextureFromImage(playerInage);

	playerPos = { 512.0f, static_cast<float>(GetScreenHeight() - texture.height) };
	direction = 1;
	speed = 1000.0f;

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
}

void Player::render()
{
	DrawTexturePro(texture, source, destination, { 0, 0 }, 0.0f, WHITE);
}
