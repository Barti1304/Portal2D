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

	renderer.getCamera().setZoom(glm::cos(glfwGetTime()) * 0.5f + 1.0f);
}

void Game::render()
{
	renderer.clearScreen(glm::vec3{ 0.1f, 0.15f, 0.2f });

	renderer.renderRectangle(glm::vec2{ glm::sin(glfwGetTime()), glm::cos(glfwGetTime()) });

	renderer.swapBuffers();
}
