#pragma once

#include "Renderer.h"

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
