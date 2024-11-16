#pragma once

#include "GameObject.h"
#include "Platform.h"
#include "Physics.h"

#include <unordered_map>
#include <string>

class GameObjectRegistry
{
public:
	GameObjectRegistry() = default;
	~GameObjectRegistry();

	void addGameObject(GameObject* gameObj);

	GameObject* operator[](const std::string& ID) const { return mapGameObjects.at(ID); }
	std::unordered_map<std::string, GameObject*>::const_iterator begin() const { return mapGameObjects.cbegin(); }
	std::unordered_map<std::string, GameObject*>::const_iterator end() const { return mapGameObjects.cend(); }

private:
	Physics* worldPhysicsRef;
	static unsigned int IDcounter;
	std::unordered_map<std::string, GameObject*> mapGameObjects;
};
