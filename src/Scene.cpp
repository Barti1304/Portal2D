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
		gameObjectRegistry.addGameObject(new Platform(physics.createBody({ i * 0.5f, i * 0.5f }, { 0.5f, 0.5f }, 0.0f)));

	gameObjectRegistry.addGameObject(new Platform(physics.createBody({ -6.0f, -4.0f }, { 1.5f, 0.5f }, 0.0f)));

	gameObjectRegistry.addGameObject(new Platform(physics.createBody({ 0.0f,5.0f }, { 1.0f, 1.0f }, 45.0f, b2_dynamicBody)));
}
