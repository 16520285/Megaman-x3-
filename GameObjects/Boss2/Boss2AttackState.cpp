#include "Boss2State.h"
#include "Boss2AttackState.h"
#include "Boss2StandingState.h"
#include "Boss2.h"

//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Boss2AttackState::Boss2AttackState(Boss2Data *Boss2Data)
{
	this->mBoss2Data = Boss2Data;
	this->mBoss2Data->Boss2->SetVx(0);
	this->mBoss2Data->Boss2->SetVy(0);
	count = 0;
	time = 300;
	
	_isLeft = this->isLeft();
}


Boss2AttackState::~Boss2AttackState()
{

}

void Boss2AttackState::Update(float dt)
{
	count++;
	if (_isLeft)
	{
		
		this->mBoss2Data->Boss2->SetVx(300);
		if (this->mBoss2Data->Boss2->GetPosition().x >= 14417.3 + 30)
		{
			this->mBoss2Data->Boss2->SetVx(0);
			if (count == 100)
			{
			this->mBoss2Data->Boss2->SetState(new Boss2StandingState(this->mBoss2Data));
			}
		}
	}

	else {
		
		this->mBoss2Data->Boss2->SetVx(-300);
		if (this->mBoss2Data->Boss2->GetPosition().x <= 14417.3 - 320)
		{
			this->mBoss2Data->Boss2->SetVx(0);
			if (count == 100)
			{
			this->mBoss2Data->Boss2->SetState(new Boss2StandingState(this->mBoss2Data));
			}
		}
	}
	
	
}
	
	
	/*this->mBoss2Data->Boss2->SetVx(-300);
	if (this->mBoss2Data->Boss2->GetPosition().x<= 14417.3 - 350)
	{
		this->mBoss2Data->Boss2->SetVx(0);
		if (count==100)
		{
			this->mBoss2Data->Boss2->SetState(new Boss2StandingState(this->mBoss2Data));
		}
	}*/




Boss2State::StateName Boss2AttackState::GetState()
{
	return Boss2State::Attack;
}

bool Boss2AttackState::isLeft()
{
	if (this->mBoss2Data->Boss2->GetPosition().x <= (14417.3 - 200))
		return true;
	 return false;
}
