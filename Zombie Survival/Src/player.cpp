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

	playerPos = { static_cast<float>(GetScreenWidth() / 2.0f), static_cast<float>(GetScreenHeight() - texture.height)};

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
	if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT))
	{ DrawTexturePro(playerRun, { direction * playerRun.width / 6.0f * updateAnimations(6), 0.0f, direction * playerRun.width / 6.0f,
	  static_cast<float>(playerRun.height) }, { playerPos.x, playerPos.y, playerRun.width / 6.0f, static_cast<float>(playerRun.height) },
	  { 0.0f, 0.0f }, 0.0f, WHITE); 
	}

	else 
	{ DrawTexturePro(playerIdle, { direction * playerIdle.width / 4.0f * updateAnimations(4), 0.0f, direction * playerIdle.width / 4.0f,
	  static_cast<float>(playerIdle.height) }, { playerPos.x, playerPos.y, playerIdle.width / 4.0f, static_cast<float>(playerIdle.height) },
	  { 0.0f, 0.0f }, 0.0f, WHITE);
	}
}

int Player::updateAnimations(int maxFrame)
{
	runningTime += GetFrameTime();

	if (runningTime >= updateTime)
	{
		runningTime = 0.0f;
		currentFrame++;

		if (currentFrame > maxFrame) { currentFrame = 0; }
	}

	return currentFrame;
}