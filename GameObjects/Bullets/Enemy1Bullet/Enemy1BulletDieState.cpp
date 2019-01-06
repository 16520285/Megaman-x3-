
#include "Enemy1BulletDieState.h"
#include "Enemy1Bullet.h"
//#include "Enemy1FallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy1BulletDieState::Enemy1BulletDieState(Enemy1BulletData *Enemy1Data)
{
    this->enemy1BulletData = Enemy1Data;
    this->enemy1BulletData->Enemy1Bullet->SetVx(0);
	this->enemy1BulletData->Enemy1Bullet->SetVy(0);
	this->enemy1BulletData->Enemy1Bullet->isDestroyed = true;
	this->enemy1BulletData->Enemy1Bullet->damage = 0;
	count = 0;
	
}


Enemy1BulletDieState::~Enemy1BulletDieState()
{
}

void Enemy1BulletDieState::Update(float dt)
{
	count++;
	if (count == 15) this->enemy1BulletData->Enemy1Bullet->isDeleted = true;
	
}



BulletState::StateName Enemy1BulletDieState::GetState()
{
    return BulletState::Die;
}
