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

	renderer.adjustCameraSizeToWindowSize(true);
}

void Game::render()
{
	renderer.clearScreen(glm::vec3{ 0.1f, 0.15f, 0.2f });

	renderer.renderRectangle({ 0.25f, 1.0f, 0.5f }, { glm::sin(glfwGetTime()) * 2.5f, glm::cos(glfwGetTime()) * 2.5f }, { 3.0f, 3.0f }, glm::sin(glfwGetTime()) * 180.0f);

	renderer.swapBuffers();
}

float Game::getDeltaTime()
{
	static float lastTime{}, deltaTime{};
	deltaTime = glfwGetTime() - lastTime;
	lastTime = glfwGetTime();

	return deltaTime;
}

int Game::getFPS()
{
	return 1.0f / getDeltaTime();
}
