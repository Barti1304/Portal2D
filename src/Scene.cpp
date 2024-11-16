#include "Scene.h"

unsigned int Scene::IDcounter = 0;

Scene::~Scene()
{

}

void Scene::initialize()
{
	physics.initialize();

	this->loadTestScene();
}

void Scene::updateScene()
{
	physics.update();
}

void Scene::loadTestScene()
{
	for (int i = -8; i < 4; ++i)
		this->addPlatform({ i * 0.5f, i * 0.5f }, { 0.5f, 0.5f }, 0.0f);

	this->addPlatform({ -6.0f, -4.0f }, { 1.5f, 0.5f }, 0.0f);

	this->addCube({ 0.0f,5.0f }, 45.0f);
}

void Scene::addPlatform(glm::vec2 pos, glm::vec2 size, float rot)
{
	gameObjectRegistry.addGameObject(new Platform(physics.createBody(pos, size, rot)));
}

void Scene::addCube(glm::vec2 pos, float rot)
{
	gameObjectRegistry.addGameObject(new Platform(physics.createBody(pos, { 1.0f, 1.0f }, rot, b2_dynamicBody)));
}

