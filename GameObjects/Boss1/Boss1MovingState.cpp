#include "Boss1State.h"
#include "Boss1MovingState.h"
#include "Boss1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss1MovingState::Boss1MovingState(Boss1Data *Boss1Data)
{
	this->mBoss1Data = Boss1Data;
	this->mBoss1Data->Boss1->SetVx(0);
	this->mBoss1Data->Boss1->SetVy(0);
	this->mBoss1Data->movingTime++;
	count = 0;
	time = 50;
}


Boss1MovingState::~Boss1MovingState()
{
	
}

void Boss1MovingState::Update(float dt)
{
	if (this->mBoss1Data->movingTime == 3 || this->mBoss1Data->movingTime == 6)
	{
		this->mBoss1Data->Boss1->SetState(new Boss1StandingState(this->mBoss1Data));
	
	}
	count++;
	if (count == time)
	{
		this->mBoss1Data->Boss1->SetVy(0);
		this->mBoss1Data->Boss1->SetVx(-550);
	}
	if (count == (time*2))
	{
		this->mBoss1Data->Boss1->SetVx(0);
		this->mBoss1Data->Boss1->SetVy(-350);
		
	}
	if (count == (time*3))
	{
		this->mBoss1Data->Boss1->SetVy(0);
		this->mBoss1Data->Boss1->SetVx(550);
	
	}
	if (count == (time*4))
	{
		this->mBoss1Data->Boss1->SetVx(0);
		this->mBoss1Data->Boss1->SetVy(350);
		

	}
	if (count == (time*5))
	{
		this->mBoss1Data->Boss1->SetVy(0);
		this->mBoss1Data->Boss1->SetVx(0);
		this->mBoss1Data->Boss1->SetState(new Boss1MovingZiczacState(this->mBoss1Data));
		
	
	}
	

}



Boss1State::StateName Boss1MovingState::GetState()
{
	return Boss1State::Moving;
}

