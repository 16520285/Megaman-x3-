#include "ShurikenState.h"
#include "ShurikenStickState.h"

//#include "PlayerFallingState.h"



ShurikenMovingState::ShurikenMovingState(ShurikenData *ShurikenData)
{
	this->mShurikenData = ShurikenData;
	this->mShurikenData->Shuriken->SetVx(0);
	this->mShurikenData->Shuriken->SetVy(0);
	count = 0;
	time = 200;
}


ShurikenMovingState::~ShurikenMovingState()
{

}

void ShurikenMovingState::Update(float dt)
{
	if (this->mShurikenData->Shuriken->mCurrentReverse)	this->mShurikenData->Shuriken->SetVx(400);
	else this->mShurikenData->Shuriken->SetVx(-400);
	if ((this->mShurikenData->Shuriken->GetPosition().x <= 14417.3 - 360)
		|| (this->mShurikenData->Shuriken->GetPosition().x >= 14417.3 + 80))
		this->mShurikenData->Shuriken->SetState(new ShurikenStickState(this->mShurikenData));
	
}



ShurikenState::StateName ShurikenMovingState::GetState()
{
	return ShurikenState::Moving;
}

