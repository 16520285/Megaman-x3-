#include "Boss1State.h"
#include "Boss1HorizontalState.h"
#include "Boss1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss1HorizontalState::Boss1HorizontalState(Boss1Data *Boss1Data)
{
	this->mBoss1Data = Boss1Data;
	this->mBoss1Data->Boss1->SetVx(0);
	this->mBoss1Data->Boss1->SetVy(0);
	//this->mBoss1Data->horizontalTime++;
	this->count = 0;
	this->time = 340;
}


Boss1HorizontalState::~Boss1HorizontalState()
{

}

void Boss1HorizontalState::Update(float dt)
{
		//this->mBoss1Data->Boss1->SetVx(-300);
	
	count++;

		
	if (this->mBoss1Data->Boss1->GetPosition().x<= 6304-380)
	{
		
		this->mBoss1Data->Boss1->SetVx(0);
		this->mBoss1Data->Boss1->SetVx(500);
	
		
	}
	if (this->mBoss1Data->Boss1->GetPosition().x >= 6304 +80)
	{
		this->mBoss1Data->Boss1->SetVx(0);
		this->mBoss1Data->Boss1->SetVx(-500);
	
	}
	if(count==time)
		this->mBoss1Data->Boss1->SetState(new Boss1MovingZiczacState(this->mBoss1Data));
}


Boss1State::StateName Boss1HorizontalState::GetState()
{
	return Boss1State::Horizontal;
}

