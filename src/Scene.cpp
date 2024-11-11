#include "Scene.h"

Scene::~Scene()
{

}

void Scene::initialize()
{
	physics.initialize();

	this->addGameObject(new Platform(physics.createBody({ 0.0f,-5.0f }, { 5.0f, 1.0f }, 0.0f)), "floor");
}

void Scene::updateScene()
{
	physics.update();
}

void Scene::addGameObject(GameObject* gameObj, const char* ID)
{
	if (mapGameObjects.find(ID) != mapGameObjects.end())
		mapGameObjects[ID] = gameObj;
	else
		std::cerr << "[ERROR] game object with id: " << ID << " already exists\n";
}
