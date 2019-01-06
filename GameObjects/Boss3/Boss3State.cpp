#include "Boss3State.h"






Boss3State::Boss3State(Boss3Data *Boss3Data)
{
	this->mBoss3Data = Boss3Data;
}

Boss3State::Boss3State()
{
}
Boss3State::~Boss3State()
{
}

void Boss3State::Update(float dt)
{

}

void Boss3State::HandleKeyboard(std::map<int, bool> keys)
{

}
void Boss3State::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
