#pragma once

#include <glm/glm.hpp>
#include <box2d/box2d.h>

#include <unordered_map>

class Physics
{
public:
	Physics() = default;
	~Physics();

	void initialize();
	void update();

	b2BodyId createPhysicsBody(glm::vec2 pos, glm::vec2 size, float rotation, b2BodyType type = b2_staticBody);

	b2WorldId getWorldID() { return worldID; }

private:
	b2WorldId worldID;
};
