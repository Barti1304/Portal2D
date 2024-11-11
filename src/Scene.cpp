#include "Scene.h"

Scene::~Scene()
{

}

void Scene::initialize()
{
	physics.initialize();
}

void Scene::updateScene()
{
	physics.update();
}
