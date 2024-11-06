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
	renderer.clearScreen(glm::vec3{ 0.1f, 0.15f, 0.2f });

	renderer.swapBuffers();
}
