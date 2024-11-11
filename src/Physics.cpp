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

	///

	b2BodyDef cubeDef = b2DefaultBodyDef();
	cubeDef.type = b2_dynamicBody;
	cubeDef.position = b2Vec2{ 0.0f, 5.0f };
	b2BodyId cubeID = b2CreateBody(worldID, &cubeDef);

	b2Polygon dynamicBox = b2MakeBox(0.5f, 0.5f);
	b2ShapeDef cubeShapeDef = b2DefaultShapeDef();
	cubeShapeDef.density = 1.0f;
	cubeShapeDef.friction = 0.3f;
	b2CreatePolygonShape(cubeID, &cubeShapeDef, &dynamicBox);
}

void Physics::update()
{
	b2World_Step(worldID, 1.0f / 60.0f, 4);
}

b2BodyId Physics::createPhysicsBody(glm::vec2 pos, glm::vec2 size, float rotation, b2BodyType type)
{
	b2BodyDef bodyDef = b2DefaultBodyDef();
	bodyDef.type = type;
	bodyDef.position = b2Vec2{ pos.x, pos.y };
	b2BodyId bodyID = b2CreateBody(worldID, &bodyDef);

	b2Polygon poly = b2MakeBox(size.x * 0.5f, size.y * 0.5f);
	b2ShapeDef shapeDef = b2DefaultShapeDef();
	b2CreatePolygonShape(bodyID, &shapeDef, &poly);

	return bodyID;
}
