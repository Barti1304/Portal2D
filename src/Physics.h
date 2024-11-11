#pragma once

#include <box2d/box2d.h>

#include <unordered_map>

class Physics
{
public:
	Physics() = default;
	~Physics();

	void initialize();

	void update();

	b2WorldId getWorldID() { return worldID; }

private:
	b2WorldId worldID;
};
