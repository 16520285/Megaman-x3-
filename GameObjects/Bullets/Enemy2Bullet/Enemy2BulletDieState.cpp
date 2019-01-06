
#include "Enemy2BulletDieState.h"
#include "Enemy2Bullet.h"
//#include "Enemy2FallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy2BulletDieState::Enemy2BulletDieState(Enemy2BulletData *Enemy2Data)
{
    this->enemy2BulletData = Enemy2Data;
    this->enemy2BulletData->Enemy2Bullet->SetVx(0);
	this->enemy2BulletData->Enemy2Bullet->SetVy(0);
	this->enemy2BulletData->Enemy2Bullet->isDestroyed = true;
	this->enemy2BulletData->Enemy2Bullet->damage = 0;
	count = 0;
	
}


Enemy2BulletDieState::~Enemy2BulletDieState()
{
}

void Enemy2BulletDieState::Update(float dt)
{
	count++;
	if (count == 15) this->enemy2BulletData->Enemy2Bullet->isDeleted = true;
	
}



BulletState::StateName Enemy2BulletDieState::GetState()
{
    return BulletState::Die;
}
