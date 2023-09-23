#include "globals.h"

std::list<GameObject*> gameObjects;

int direction = 1;

float speed = 200.0f;

int currentFrame = 0;
float runningTime = 0.0f;
float updateTime = 1.0f / 12.0f;

float elapsedTime = 0.0f;
float dayTime = 150.0f;
float nightTime = 240.0f;

int score = 0;
int level = 1;

bool isAlive = true;

const int windowWidth = 1024;
const int windowHeight = 600;