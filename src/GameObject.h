#pragma once

#include <box2d/box2d.h>

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject();

private:
	static unsigned int IDcounter;
	unsigned int objectID;
};
