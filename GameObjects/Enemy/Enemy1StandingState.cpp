#include "Enemy1StandingState.h"
#include "Enemy1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy1StandingState::Enemy1StandingState(EnemyData1 *playerData)
{
    this->mEnemyData1 = playerData;
    this->mEnemyData1->Enemy1->SetVx(0);
    this->mEnemyData1->Enemy1->SetVy(0);
	count = 0;
	time = 50;
}


Enemy1StandingState::~Enemy1StandingState()
{
}

void Enemy1StandingState::Update(float dt)
{
	
	count++;
	if (count == time) this->mEnemyData1->Enemy1->SetState(new Enemy1ShootingState(this->mEnemyData1));
}



Enemy1State::StateName Enemy1StandingState::GetState()
{
    return Enemy1State::Standing;
}
