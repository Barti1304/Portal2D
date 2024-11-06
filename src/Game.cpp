#include "Game.h"

Game::Game(int wWidth, int wHeight, const char* wTitle)
{
	renderer.initialize(wWidth, wHeight, wTitle);
}

Game::~Game()
{

}

void Game::run()
{
	while (renderer.isStillRunning())
	{
		this->update();
		this->render();
	}

}

void Game::update()
{
	glfwPollEvents();
}

void Game::render()
{
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	renderer.swapBuffers();
}
