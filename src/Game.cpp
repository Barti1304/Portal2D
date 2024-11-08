#include "Game.h"

Game::Game(int wWidth, int wHeight)
{
	renderer.initialize(wWidth, wHeight);
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

	renderer.renderRectangle(glm::vec2{ glm::sin(glfwGetTime()), glm::cos(glfwGetTime()) });

	renderer.swapBuffers();
}
