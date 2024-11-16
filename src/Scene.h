#pragma once

#include <box2d/box2d.h>

#include "Physics.h"
#include "GameObject.h"
#include "Platform.h"
#include "GameObjectRegistry.h"

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

	void loadTestScene();

	const GameObjectRegistry* const getGameObjectRegistry() const { return &gameObjectRegistry; };

private:
	static unsigned int IDcounter;

	void addPlatform(glm::vec2 pos, glm::vec2 size, float rot);
	void addCube(glm::vec2 pos, float rot);

	Physics physics;
	GameObjectRegistry gameObjectRegistry;
};
