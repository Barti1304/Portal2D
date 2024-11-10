#pragma once

#include <box2d/box2d.h>

#include "Renderer.h"

class Scene
{
public:
	Scene() = default;
	~Scene();

	void initialize();
	void updateScene();

	b2WorldId getWorldID() { return worldID; }

private:
	b2WorldId worldID;
};
