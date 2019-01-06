#include "Brick2StandingState.h"


#include "Brick2.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Brick2StandingState::Brick2StandingState(Brick2Data *playerData)
{
	this->mBrick2Data = playerData;
	
}


Brick2StandingState::~Brick2StandingState()
{
}

void Brick2StandingState::Update(float dt)
{
	
	if (mBrick2Data->Brick2->HP < 0) this->mBrick2Data->Brick2->SetState(new Brick2DieState(this->mBrick2Data));

	
}



Brick2State::StateName Brick2StandingState::GetState()
{
	return Brick2State::Standing;
}
