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

	void addGameObject(GameObject* gameObj, const char* ID);

private:
	Physics physics;
	std::unordered_map<const char*, GameObject*> mapGameObjects;
};
