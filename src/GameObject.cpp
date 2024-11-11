#include "GameObject.h"

void GameObject::setBodyID(b2BodyId ID)
{
	bodyID = ID;
}

GameObject::GameObject(b2BodyId bID) : bodyID{ bID } {}

b2BodyId GameObject::getBodyID()
{
	return bodyID;
}

glm::vec2 GameObject::getPosition()
{
	b2Vec2 pos = b2Body_GetPosition(bodyID);
	return glm::vec2{ pos.x, pos.y };
}

glm::vec2 GameObject::getSize()
{
	b2ShapeId shapeID;
	b2Body_GetShapes(bodyID, &shapeID, 1);
	b2Polygon poly = b2Shape_GetPolygon(shapeID);

	float width = glm::abs(b2Length(b2Sub(poly.vertices[0], poly.vertices[1])));
	float height = glm::abs(b2Length(b2Sub(poly.vertices[0], poly.vertices[2])));

	return glm::vec2{ width, height };
}

float GameObject::getRotation()
{
	return b2Rot_GetAngle(b2Body_GetRotation(bodyID));
}
