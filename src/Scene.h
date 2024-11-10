#pragma once

#include <GLFW/glfw3.h>
#include <box2d/box2d.h>

class Scene
{
public:
	Scene() = default;

	void initialize();
	void updateScene();

private:
	b2WorldId worldID;
};
