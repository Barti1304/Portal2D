#pragma once

#include "Renderer.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Game
{
public:
	Game(int wWidth, int wHeight);
	~Game();

	void run();

private:
	void update();
	void render();

	Renderer renderer;
};
