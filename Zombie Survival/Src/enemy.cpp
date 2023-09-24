#include "enemy.h"

Enemy::Enemy()
{
	gameObjects.push_back(this);

	texture = LoadTexture("Textures/Enemy/enemyAttack.png");
	enemyPos = { static_cast<float>(windowWidth - texture.width), static_cast<float>(windowHeight - texture.height) };
}

Enemy::~Enemy() { UnloadTexture(texture); }

void Enemy::update()
{

}

void Enemy::render()
{
	DrawTexturePro(texture, { direction * texture.width / 4.0f, 0.0f, direction * texture.width / 4.0f,
	static_cast<float>(texture.height) }, { enemyPos.x, enemyPos.y, texture.width / 4.0f, static_cast<float>(texture.height) },
	{ 0.0f, 0.0f }, 0.0f, WHITE);
}