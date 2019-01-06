#include "Boss2State.h"
#include "Boss2ShootingState.h"

//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss2ShootingState::Boss2ShootingState(Boss2Data *Boss2Data)
{
	this->mBoss2Data = Boss2Data;
	this->mBoss2Data->Boss2->SetVx(0);
	this->mBoss2Data->Boss2->SetVy(0);
	count = 0;
	time = 300;
	this->mBoss2Data->Boss2->onFired();
}


Boss2ShootingState::~Boss2ShootingState()
{

}

void Boss2ShootingState::Update(float dt)
{
	count++;
	if (count == 40)
		this->mBoss2Data->Boss2->SetState(new Boss2StandingState(this->mBoss2Data));




}



Boss2State::StateName Boss2ShootingState::GetState()
{
	return Boss2State::Shooting;
}
