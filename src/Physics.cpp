#include "Physics.h"

Physics::~Physics()
{
	b2DestroyWorld(worldID);
}

void Physics::initialize()
{
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = b2Vec2{ 0.0f, -9.8f };
	worldID = b2CreateWorld(&worldDef);
}

void Physics::update()
{
	b2World_Step(worldID, 1.0f / 60.0f, 4);
}

b2BodyId Physics::createBody(glm::vec2 pos, glm::vec2 size, float rot, b2BodyType type)
{
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.type = type;
	bodyDef.rotation = b2MakeRot(glm::radians(rot));
	bodyDef.position = b2Vec2{ pos.x, pos.y };

	b2BodyId bodyID = b2CreateBody(worldID, &bodyDef);
	b2Polygon poly = b2MakeBox(size.x * 0.5f, size.y * 0.5f);
	b2ShapeDef shapeDef = b2DefaultShapeDef();

	b2CreatePolygonShape(bodyID, &shapeDef, &poly);

	return bodyID;
}
