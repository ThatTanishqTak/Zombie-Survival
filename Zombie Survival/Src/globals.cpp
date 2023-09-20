// This file is the definition of all the global variables

#include "globals.h"

std::list<GameObject*> gameObjects;

int score = 0;
int direction = 1;

float speed = 200.0f;

int currentFrame = 0;
float runningTime = 0.0f;
float updateTime = 1.0f / 12.0f;