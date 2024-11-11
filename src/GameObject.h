#pragma once

#include <box2d/box2d.h>
#include <glm/glm.hpp>

class GameObject
{
public:
	GameObject(b2BodyId bID);
	virtual ~GameObject() = 0;

	virtual void update() = 0;


	b2BodyId getBodyID();
	glm::vec2 getPosition();
	glm::vec2 getSize();
	float getRotation();

protected:
	const char* objectID;

	void setBodyID(b2BodyId ID);
	b2BodyId bodyID;
};
