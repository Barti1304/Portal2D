#pragma once

#include "Renderer.h"
#include "Scene.h"

class Game
{
public:
	Game(int wWidth, int wHeight);
	~Game();

	void run();

private:
	void update();
	void render();

	static float getDeltaTime();
	static int getFPS();

	Renderer renderer;
	Scene scene;
};
