#include "GameObjectRegistry.h"

unsigned int GameObjectRegistry::IDcounter = 0;

GameObjectRegistry::~GameObjectRegistry()
{

}

void GameObjectRegistry::addGameObject(GameObject* gameObj)
{
	std::string tempID{ "obj_" };
	tempID.append(std::to_string(IDcounter++));

	mapGameObjects.insert({ tempID.c_str(), gameObj });
}