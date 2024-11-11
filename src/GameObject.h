#pragma once

#include <box2d/box2d.h>

class GameObject
{
public:
	GameObject() = default;
	virtual ~GameObject() = 0;

private:
	const char* objectID;
};
