#include "ShurikenState.h"






ShurikenState::ShurikenState(ShurikenData *ShurikenData)
{
	this->mShurikenData = ShurikenData;
}

ShurikenState::ShurikenState()
{
}
ShurikenState::~ShurikenState()
{
}

void ShurikenState::Update(float dt)
{

}

void ShurikenState::HandleKeyboard(std::map<int, bool> keys)
{

}
void ShurikenState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
