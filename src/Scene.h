#pragma once

#include <box2d/box2d.h>

#include "Renderer.h"
#include "Physics.h"

class Scene
{
public:
	Scene() = default;
	~Scene();

	void initialize();
	void updateScene();

private:
	Physics physics;
};
