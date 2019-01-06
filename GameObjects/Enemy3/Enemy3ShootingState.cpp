#include "Enemy3ShootingState.h"
#include "Enemy3StandingState.h"

#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

Enemy3ShootingState::Enemy3ShootingState(Enemy3Data *playerData)
{
    this->mEnemyData3 = playerData;
	this->mEnemyData3->Enemy3->SetVx(0);
    this->mEnemyData3->Enemy3->SetVy(0);
	this->mEnemyData3->Enemy3->onFired();
	count = 0;
	time = 200;
    
	    noPressed = false;
}


Enemy3ShootingState::~Enemy3ShootingState()
{

}

void Enemy3ShootingState::Update(float dt)
{
	count++; 
	if (count == time) this->mEnemyData3->Enemy3->SetState(new Enemy3ShootingState(this->mEnemyData3));
	

 
}



Enemy3State::StateName Enemy3ShootingState::GetState()
{
    return Enemy3State::Shooting;
}
