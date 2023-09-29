#include "player.h"

Player::Player()
{
	gameObjects.push_back(this);

	playerIdle = LoadTexture("Textures/Player/playerIdle.png");
	playerRun = LoadTexture("Textures/Player/playerRun.png");
	playerAttack = LoadTexture("Textures/Player/playerAttack.png");
	playerHurt = LoadTexture("Textures/Player/playerHurt.png");
	playerDead = LoadTexture("Textures/Player/playerDead.png");

	playerPos = { static_cast<float>(windowWidth / 2.0f), static_cast<float>(windowHeight - playerIdle.height)};
	source = { 0.0f, 0.0f, playerIdle.width / 6.0f, static_cast<float>(playerIdle.height) };
}

Player::~Player()
{
	UnloadTexture(playerIdle);
	UnloadTexture(playerRun);
	UnloadTexture(playerAttack);
	UnloadTexture(playerHurt);
	UnloadTexture(playerDead);
}

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

	if (playerPos.x <= 0) { playerPos.x = 0; }
	if (playerPos.x + playerRun.width / 6.0f >= windowWidth) { playerPos.x = windowWidth - playerRun.width / 6.0f; }
}

void Player::render()
{
	DrawTextureRec(playerIdle, source, playerPos, WHITE);
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