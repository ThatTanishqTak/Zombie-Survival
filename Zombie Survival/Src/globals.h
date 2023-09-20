// This file contains the global variables

#ifndef GLOBALS_H
#define GLOBALS_H

#include "gameobjects.h"
#include <list>

extern std::list<GameObject*> gameObjects;

extern int score;
extern int direction;

extern float speed;

#endif