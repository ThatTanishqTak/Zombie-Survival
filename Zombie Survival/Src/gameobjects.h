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