#include "Boss1State.h"
#include "Boss1MovingZiczacState.h"
#include "Boss1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss1MovingZiczacState::Boss1MovingZiczacState(Boss1Data *Boss1Data)
{
	this->mBoss1Data = Boss1Data;
	this->mBoss1Data->Boss1->SetVx(0);
	this->mBoss1Data->Boss1->SetVy(0);
	this->mBoss1Data->movingZiczacTime++;
	count = 0;
    time = 50;
}


Boss1MovingZiczacState::~Boss1MovingZiczacState()
{

}

void Boss1MovingZiczacState::Update(float dt)
{
	
	
	count++;
	if (count == time)
		this->mBoss1Data->Boss1->SetVx(-600);
	if (count == time + 30 )
		this->mBoss1Data->Boss1->SetVy(-300);
	if (this->mBoss1Data->Boss1->GetPosition().x <= 6304 - 380)
	{
		this->mBoss1Data->Boss1->SetVx(600);
		this->mBoss1Data->Boss1->SetVy(300);


	}
	if (this->mBoss1Data->Boss1->GetPosition().y >= 2294.67)
	{
		this->mBoss1Data->Boss1->SetVy(0);
	}
	if (count == time + 90 )
	{
		this->mBoss1Data->Boss1->SetVx(0);
	   
		this->mBoss1Data->Boss1->SetState(new Boss1StandingState(this->mBoss1Data));
	}
}



Boss1State::StateName Boss1MovingZiczacState::GetState()
{
	return Boss1State::MovingZiczac;
}

