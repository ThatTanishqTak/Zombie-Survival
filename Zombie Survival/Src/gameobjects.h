// This is a leaser level version of the Game-Object system used in Unity

#ifndef GAMEOBJECTS_H
#define GAMEOBJECTS_H

class GameObject
{
public:
	GameObject() = default;
	~GameObject() = default;

	virtual void update() = 0;
	virtual void render() = 0;
};

#endif