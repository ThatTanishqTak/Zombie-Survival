#include "globals.h"
#include "raylib.h"

std::list<GameObject*> gameObjects;

const int windowWidth = 1024;
const int windowHeight = 600;

bool isAlive = true;

int direction = 1;
float health = 100.0f;
float speed = 200.0f;

int currentFrame = 0;
float runningTime = 0.0f;
float updateTime = 1.0f / 12.0f;

float elapsedTime = 0.0f;
float dayTime = 150.0f;
float nightTime = 240.0f;