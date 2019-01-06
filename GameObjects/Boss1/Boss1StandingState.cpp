#include "Boss1State.h"
#include "Boss1StandingState.h"
#include "Boss1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss1StandingState::Boss1StandingState(Boss1Data *Boss1Data)
{
	this->mBoss1Data = Boss1Data;
	this->mBoss1Data->Boss1->SetVx(0);
	this->mBoss1Data->Boss1->SetVy(0);
	this->mBoss1Data->movingZiczacTime++;
	count = 0;
	time = 100;
}


Boss1StandingState::~Boss1StandingState()
{

}

void Boss1StandingState::Update(float dt)
{

	count++;
	if (this->mBoss1Data->movingZiczacTime == 5)
		this->mBoss1Data->Boss1->SetState(new Boss1MovingZiczacState(this->mBoss1Data));
	if (count == time)
	{
		
		this->mBoss1Data->Boss1->SetState(new Boss1MovingState(this->mBoss1Data));
	}
	
}



Boss1State::StateName Boss1StandingState::GetState()
{
	return Boss1State::Standing;
}

