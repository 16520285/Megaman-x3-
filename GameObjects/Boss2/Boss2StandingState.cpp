#include "Boss2State.h"
#include "Boss2ShootingState.h"
#include "Boss2AttackState.h"

//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss2StandingState::Boss2StandingState(Boss2Data *Boss2Data)
{
	this->mBoss2Data = Boss2Data;
	this->mBoss2Data->Boss2->SetVx(0);
	this->mBoss2Data->Boss2->SetVy(0);
	count = 0;
	time = 80;
	this->mBoss2Data->standingTime++;
	
	this->mBoss2Data->isAttack = !this->mBoss2Data->isAttack;
	
	if (this->mBoss2Data->standingTime == this->mBoss2Data->standingTime2)
	{
		this->mBoss2Data->Boss2->SetReverse(true);
		this->mBoss2Data->standingTime2 += 4;
	}
	if (this->mBoss2Data->standingTime == this->mBoss2Data->standingTime3)
	{
		this->mBoss2Data->Boss2->SetReverse(false);
	this->mBoss2Data->standingTime3 += 4;
	}
}


Boss2StandingState::~Boss2StandingState()
{

}

void Boss2StandingState::Update(float dt)
{
	count++;
	if (count == time)
		if (this->mBoss2Data->isAttack)
			this->mBoss2Data->Boss2->SetState(new Boss2AttackState(this->mBoss2Data));
		else
		this->mBoss2Data->Boss2->SetState(new Boss2ShootingState(this->mBoss2Data));
	



}



Boss2State::StateName Boss2StandingState::GetState()
{
	return Boss2State::Standing;
}
