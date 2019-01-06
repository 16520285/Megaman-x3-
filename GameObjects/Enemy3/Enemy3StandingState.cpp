#include "Enemy3StandingState.h"
#include "Enemy3.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy3StandingState::Enemy3StandingState(Enemy3Data *playerData)
{
    this->mEnemyData3 = playerData;
    this->mEnemyData3->Enemy3->SetVx(0);
    this->mEnemyData3->Enemy3->SetVy(0);
	count = 0;
	time = 50;
}


Enemy3StandingState::~Enemy3StandingState()
{
}

void Enemy3StandingState::Update(float dt)
{
	
	count++;
	if (count == time) this->mEnemyData3->Enemy3->SetState(new Enemy3FlyingState(this->mEnemyData3));
}



Enemy3State::StateName Enemy3StandingState::GetState()
{
    return Enemy3State::Standing;
}
