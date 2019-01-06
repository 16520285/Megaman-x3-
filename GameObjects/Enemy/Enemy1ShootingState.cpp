#include "Enemy1ShootingState.h"
#include "Enemy1StandingState.h"

#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

Enemy1ShootingState::Enemy1ShootingState(EnemyData1 *playerData)
{
    this->mEnemyData1 = playerData;
	this->mEnemyData1->Enemy1->SetVx(0);
    this->mEnemyData1->Enemy1->SetVy(0);
	this->mEnemyData1->Enemy1->timeshot++;
	count = 0;
	time = 20;
    noPressed = false;
	
	this->mEnemyData1->Enemy1->onFired();
}


Enemy1ShootingState::~Enemy1ShootingState()
{

}

void Enemy1ShootingState::Update(float dt)
{
	
	
	count++; 
	if (count == time)
	{
		if (this->mEnemyData1->Enemy1->timeshot!=3)
		{
			this->mEnemyData1->Enemy1->SetState(new Enemy1ShootingState(this->mEnemyData1));
		}
		
	}
	if (count==time*5) this->mEnemyData1->Enemy1->SetState(new Enemy1JumpingState(this->mEnemyData1));

 
}



Enemy1State::StateName Enemy1ShootingState::GetState()
{
    return Enemy1State::Shooting;
}
