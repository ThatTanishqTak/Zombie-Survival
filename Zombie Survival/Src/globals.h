#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobjects.h"
#include <list>

extern std::list<GameObject*> gameObjects;

extern int direction;
extern float speed;
extern float health;

extern int currentFrame;
extern float runningTime;
extern float updateTime;

extern float elapsedTime;
extern float dayTime;
extern float nightTime;

extern bool isAlive;

extern const int windowWidth;
extern const int windowHeight;

#endif