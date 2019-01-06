#include "BeeState.h"






BeeState::BeeState(BeeData *BeeData)
{
	this->mBeeData = BeeData;
}

BeeState::BeeState()
{
}
BeeState::~BeeState()
{
}

void BeeState::Update(float dt)
{

}

void BeeState::HandleKeyboard(std::map<int, bool> keys)
{

}
void BeeState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
