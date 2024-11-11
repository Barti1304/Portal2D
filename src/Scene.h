#pragma once

#include <box2d/box2d.h>

#include "Physics.h"
#include "GameObject.h"
#include "Platform.h"

#include <iostream>
#include <unordered_map>

class Scene
{
public:
	Scene() = default;
	~Scene();

	void initialize();
	void updateScene();

	int getGameObjectsCount() { return mapGameObjects.size(); }

	void addGameObject(GameObject* gameObj);

	GameObject* operator[](unsigned int ID) const;

	std::unordered_map<unsigned int, GameObject*>::iterator begin() { return mapGameObjects.begin(); }
	std::unordered_map<unsigned int, GameObject*>::iterator end() { return mapGameObjects.end(); }

private:
	static unsigned int IDcounter;

	Physics physics;
	std::unordered_map<unsigned int, GameObject*> mapGameObjects;
};
