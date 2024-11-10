#include "Scene.h"

void Scene::init()
{
	b2WorldDef worldDef = b2DefaultWorldDef();
	worldDef.gravity = b2Vec2{ 0.0f, -9.8f };
	worldID = b2CreateWorld(&worldDef);

	///

	b2BodyDef groundBodyDef = b2DefaultBodyDef();
	groundBodyDef.position = b2Vec2{ 0.0f, -5.0f };
	b2BodyId groundID = b2CreateBody(worldID, &groundBodyDef);

	b2Polygon groundBox = b2MakeBox(5.0f, 0.5f);
	b2ShapeDef groundShapeDef = b2DefaultShapeDef();
	b2CreatePolygonShape(groundID, &groundShapeDef, &groundBox);

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

void Scene::updateScene()
{
	b2World_Step(worldID, 1.0f / 60.0f, 4);
}
