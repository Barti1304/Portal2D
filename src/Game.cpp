#include "Game.h"

Game::Game(int wWidth, int wHeight)
{
	renderer.initialize(wWidth, wHeight);
	scene.initialize();
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

	renderer.adjustCameraSizeToWindowSize();

	scene.updateScene();
}

void Game::render()
{
	renderer.clearScreen(glm::vec3{ 0.1f, 0.15f, 0.2f });

	renderer.renderScene(&scene);

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
