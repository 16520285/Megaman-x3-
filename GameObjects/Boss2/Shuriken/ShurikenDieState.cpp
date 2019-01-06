#include "ShurikenState.h"
#include "ShurikenDieState.h"





ShurikenDieState::ShurikenDieState(ShurikenData *ShurikenData)
{
	this->mShurikenData = ShurikenData;
	this->mShurikenData->Shuriken->SetVx(0);
	this->mShurikenData->Shuriken->SetVy(0);
	count = 0;
	time = 20;
}


ShurikenDieState::~ShurikenDieState()
{
	
	
}

void ShurikenDieState::Update(float dt)
{
	count++;
	if (count == time) this->mShurikenData->Shuriken->isDeleted = true;

}



ShurikenState::StateName ShurikenDieState::GetState()
{
	return ShurikenState::Die;
}

