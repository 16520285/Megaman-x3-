#include "BrickStandingState.h"


#include "Brick.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
BrickStandingState::BrickStandingState(BrickData *playerData)
{
	this->mBrickData = playerData;
	count = 0;
	time = 400;
	//this->mBrickData->Brick->SetVy(100);
}


BrickStandingState::~BrickStandingState()
{
}

void BrickStandingState::Update(float dt)
{
	count++;
	if (count == time) 
		this->mBrickData->Brick->SetVy(0);
	
	
	if (mBrickData->Brick->HP < 0) this->mBrickData->Brick->SetState(new BrickDieState(this->mBrickData));

	
}



BrickState::StateName BrickStandingState::GetState()
{
	return BrickState::Standing;
}
