#include "BrickState.h"


BrickState::BrickState(BrickData *BrickData)
{
	this->mBrickData = BrickData;
}

BrickState::BrickState()
{
}
BrickState::~BrickState()
{
}

void BrickState::Update(float dt)
{

}

void BrickState::HandleKeyboard(std::map<int, bool> keys)
{

}
void BrickState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}