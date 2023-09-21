// This file contains the global variables

#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobjects.h"
#include <list>

extern std::list<GameObject*> gameObjects;

extern int direction;

extern float speed;


extern int currentFrame;
extern float runningTime;
extern float updateTime;

#endif