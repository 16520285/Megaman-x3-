#include "Boss1State.h"






Boss1State::Boss1State(Boss1Data *Boss1Data)
{
	this->mBoss1Data = Boss1Data;
}

Boss1State::Boss1State()
{
}
Boss1State::~Boss1State()
{
}

void Boss1State::Update(float dt)
{

}

void Boss1State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Boss1State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
