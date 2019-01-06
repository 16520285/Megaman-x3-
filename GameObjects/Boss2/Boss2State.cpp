#include "Boss2State.h"


Boss2State::Boss2State(Boss2Data *Boss2Data)
{
	this->mBoss2Data = Boss2Data;
}

Boss2State::Boss2State()
{
}
Boss2State::~Boss2State()
{
}

void Boss2State::Update(float dt)
{

}

void Boss2State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Boss2State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
