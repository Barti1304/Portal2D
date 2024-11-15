#pragma once

#include <box2d/box2d.h>

#include "Physics.h"
#include "GameObject.h"
#include "Platform.h"

#include <iostream>
#include <unordered_map>
#include <string>

class Scene
{
public:
	Scene() = default;
	~Scene();

	void initialize();
	void updateScene();

	int getGameObjectsCount() { return mapGameObjects.size(); }

	void addGameObject(GameObject* gameObj);

	GameObject* operator[](const std::string& ID) const;

	std::unordered_map<std::string, GameObject*>::iterator begin() { return mapGameObjects.begin(); }
	std::unordered_map<std::string, GameObject*>::iterator end() { return mapGameObjects.end(); }

private:
	static unsigned int IDcounter;

	Physics physics;
	std::unordered_map<std::string, GameObject*> mapGameObjects;
};
