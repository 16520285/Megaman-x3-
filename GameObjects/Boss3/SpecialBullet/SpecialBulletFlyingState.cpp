#include "SpecialBulletState.h"
#include "SpecialBulletFlyingState.h"

//#include "PlayerFallingState.h"



SpecialBulletFlyingState::SpecialBulletFlyingState(SpecialBulletData *SpecialBulletData)
{
	this->mSpecialBulletData = SpecialBulletData;

	count = 0;
	time = 200;
}


SpecialBulletFlyingState::~SpecialBulletFlyingState()
{

}

void SpecialBulletFlyingState::Update(float dt)
{
	
}



SpecialBulletState::StateName SpecialBulletFlyingState::GetState()
{
	return SpecialBulletState::Flying;
}

