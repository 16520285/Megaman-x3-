#include "SpecialBulletState.h"






SpecialBulletState::SpecialBulletState(SpecialBulletData *SpecialBulletData)
{
	this->mSpecialBulletData = SpecialBulletData;
}

SpecialBulletState::SpecialBulletState()
{
}
SpecialBulletState::~SpecialBulletState()
{
}

void SpecialBulletState::Update(float dt)
{

}

void SpecialBulletState::HandleKeyboard(std::map<int, bool> keys)
{

}
void SpecialBulletState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{

}
