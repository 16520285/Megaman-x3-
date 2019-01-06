#include "ShurikenState.h"
#include "ShurikenStickState.h"
#include "../../../GameComponents/GameLog.h"




ShurikenStickState::ShurikenStickState(ShurikenData *ShurikenData)
{
	this->mShurikenData = ShurikenData;
	this->mShurikenData->Shuriken->SetVx(0);
	this->mShurikenData->Shuriken->SetVy(0);
	count = 0;
	time = 132;
}


ShurikenStickState::~ShurikenStickState()
{

}

void ShurikenStickState::Update(float dt)
{
	count++;
	if (count == time) 
		this->mShurikenData->Shuriken->SetState(new ShurikenDieState(this->mShurikenData));


}



ShurikenState::StateName ShurikenStickState::GetState()
{
	return ShurikenState::Stick;
}

