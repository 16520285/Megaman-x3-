
#include "Enemy2ShootingState.h"

#include "../../GameComponents/GameGlobal.h"
#include "../../GameComponents/GameLog.h"

Enemy2ShootingState::Enemy2ShootingState(EnemyData2 *playerData)
{
	this->mEnemyData2 = playerData;
	this->mEnemyData2->Enemy2->SetVx(0);
	this->mEnemyData2->Enemy2->SetVy(0);
	count = 0;
	time = 200;
	this->mEnemyData2->Enemy2->onFired();
	noPressed = false;
}


Enemy2ShootingState::~Enemy2ShootingState()
{

}

void Enemy2ShootingState::Update(float dt)
{
	count++;
	if (count == time) this->mEnemyData2->Enemy2->SetState(new Enemy2StandingState(this->mEnemyData2));



}



Enemy2State::StateName Enemy2ShootingState::GetState()
{
	return Enemy2State::Shooting;
}
