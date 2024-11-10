#pragma once

#include <box2d/box2d.h>

class Scene
{
public:
	Scene() = default;

	void init();

private:
	b2WorldId worldID;
};
