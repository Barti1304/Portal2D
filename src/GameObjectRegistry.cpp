#include "GameObjectRegistry.h"

unsigned int GameObjectRegistry::IDcounter = 0;

GameObjectRegistry::~GameObjectRegistry()
{

}

void GameObjectRegistry::initialize(Physics* physics)
{
	worldPhysicsRef = physics;
}

void GameObjectRegistry::loadTestScene()
{
	for (int i = -8; i < 4; ++i)
		this->addGameObject(new Platform(worldPhysicsRef->createBody({ i * 0.5f, i * 0.5f }, { 0.5f, 0.5f }, 0.0f)));

	this->addGameObject(new Platform(worldPhysicsRef->createBody({ -6.0f, -4.0f }, { 1.5f, 0.5f }, 0.0f)));

	this->addGameObject(new Platform(worldPhysicsRef->createBody({ 0.0f,5.0f }, { 1.0f, 1.0f }, 45.0f, b2_dynamicBody)));
}


void GameObjectRegistry::addGameObject(GameObject* gameObj)
{
	std::string tempID{ "obj_" };
	tempID.append(std::to_string(IDcounter++));

	mapGameObjects.insert({ tempID.c_str(), gameObj });
}