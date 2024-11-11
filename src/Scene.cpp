#include "Scene.h"

unsigned int Scene::IDcounter = 0;

Scene::~Scene()
{

}

void Scene::initialize()
{
	physics.initialize();

	for (int i = -8; i < 4; ++i)
		this->addGameObject(new Platform(physics.createBody({ i * 0.5f, i * 0.5f }, { 0.5f, 0.5f }, 0.0f)));

	this->addGameObject(new Platform(physics.createBody({ -6.0f, -4.0f }, { 1.5f, 0.5f }, 0.0f)));

	this->addGameObject(new Platform(physics.createBody({ 0.0f,5.0f }, { 1.0f, 1.0f }, 45.0f, b2_dynamicBody)));
}

void Scene::updateScene()
{
	physics.update();
}

void Scene::addGameObject(GameObject* gameObj)
{
	mapGameObjects.insert({ IDcounter++, gameObj });
}

GameObject* Scene::operator[](unsigned int ID) const
{
	return mapGameObjects.at(ID);
}
