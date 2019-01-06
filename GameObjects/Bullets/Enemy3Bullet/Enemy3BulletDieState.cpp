
#include "Enemy3BulletDieState.h"
#include "Enemy3Bullet.h"
//#include "Enemy3FallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy3BulletDieState::Enemy3BulletDieState(Enemy3BulletData *Enemy3Data)
{
    this->enemy3BulletData = Enemy3Data;
    this->enemy3BulletData->Enemy3Bullet->SetVx(0);
	this->enemy3BulletData->Enemy3Bullet->SetVy(0);
	this->enemy3BulletData->Enemy3Bullet->isDestroyed = true;
	this->enemy3BulletData->Enemy3Bullet->damage = 0;
	count = 0;
	
}


Enemy3BulletDieState::~Enemy3BulletDieState()
{
}

void Enemy3BulletDieState::Update(float dt)
{
	count++;
	if (count == 15) this->enemy3BulletData->Enemy3Bullet->isDeleted = true;
	
}



BulletState::StateName Enemy3BulletDieState::GetState()
{
    return BulletState::Die;
}
