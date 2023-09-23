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

	playerPos = { static_cast<float>(windowWidth / 2.0f), static_cast<float>(windowHeight - texture.height)};
}

Player::~Player() { UnloadTexture(texture); }

void Player::update()
{
	if(isAlive)
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
		if (playerPos.x + texture.width / 6.0f >= windowWidth) { playerPos.x = windowWidth - texture.width / 6.0f; }

		attack(100);

		if (IsKeyPressed(KEY_R)) { isAlive = true; }
		if (IsKeyPressed(KEY_Q)) { isAlive = false; }
	}
}

void Player::render()
{
	if (isAlive)
	{
		if (IsKeyDown(KEY_A) || IsKeyDown(KEY_D) || IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_RIGHT))
		{
			DrawTexturePro(playerRun, { direction * playerRun.width / 6.0f * updateAnimations(6), 0.0f, direction * playerRun.width / 6.0f,
			static_cast<float>(playerRun.height) }, { playerPos.x, playerPos.y, playerRun.width / 6.0f, static_cast<float>(playerRun.height) },
			{ 0.0f, 0.0f }, 0.0f, WHITE);
		}

		else if (IsKeyDown(KEY_X))
		{
			DrawTexturePro(playerAttack, { direction * playerAttack.width / 6.0f * updateAnimations(6), 0.0f, direction * playerAttack.width / 6.0f,
			static_cast<float>(playerAttack.height) }, { playerPos.x, playerPos.y, playerAttack.width / 6.0f, static_cast<float>(playerAttack.height) },
			{ 0.0f, 0.0f }, 0.0f, WHITE);
		}

		else
		{
			DrawTexturePro(playerIdle, { direction * playerIdle.width / 4.0f * updateAnimations(4), 0.0f, direction * playerIdle.width / 4.0f,
			static_cast<float>(playerIdle.height) }, { playerPos.x, playerPos.y, playerIdle.width / 4.0f, static_cast<float>(playerIdle.height) },
			{ 0.0f, 0.0f }, 0.0f, WHITE);
		}
	}

	else
	{
		DrawTexturePro(playerDead, { direction * playerDead.width / 6.0f * updateAnimations(6), 0.0f, direction * playerDead.width / 6.0f,
		static_cast<float>(playerDead.height) }, { playerPos.x, playerPos.y, playerDead.width / 6.0f, static_cast<float>(playerDead.height) },
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

int Player::attack(int hitPoints) { if (IsKeyPressed(KEY_X)) { return hitPoints; } }