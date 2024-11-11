#include "Physics.h"

Physics::~Physics()
{
	b2DestroyWorld(worldID);
}
