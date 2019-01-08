#include "Enemy2StandingState.h"


#include "Enemy2.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy2StandingState::Enemy2StandingState(EnemyData2 *playerData)
{
	this->mEnemyData2 = playerData;
	this->mEnemyData2->Enemy2->SetVx(0);
	this->mEnemyData2->Enemy2->SetVy(0);
	count = 0;
	time = 100;
}


Enemy2StandingState::~Enemy2StandingState()
{
}

void Enemy2StandingState::Update(float dt)
{

	count++;
	if (count == time) this->mEnemyData2->Enemy2->SetState(new Enemy2ShootingState(this->mEnemyData2));
}



Enemy2State::StateName Enemy2StandingState::GetState()
{
	return Enemy2State::Standing;
}
