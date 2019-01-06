#include "Enemy2BulletMovingState.h"
#include "Enemy2Bullet.h"
//#include "Enemy2FallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy2BulletMovingState::Enemy2BulletMovingState(Enemy2BulletData *Enemy2Data)
{
    this->enemy2BulletData = Enemy2Data;
	
	
	count = 0;
	time = 200;
}


Enemy2BulletMovingState::~Enemy2BulletMovingState()
{

}

void Enemy2BulletMovingState::Update(float dt)
{
		if (this->enemy2BulletData->Enemy2Bullet->mCurrentReverse) this->enemy2BulletData->Enemy2Bullet->SetVx(Define::ENEMY2_BULLET_VELOCITY);
		else this->enemy2BulletData->Enemy2Bullet->SetVx(-Define::ENEMY2_BULLET_VELOCITY);
	//	GAMELOG("a:%d", this->enemy2BulletData->Enemy2Bullet->GetVx());
		count++;
		if (count == time || this->enemy2BulletData->Enemy2Bullet->isDestroyed) this->enemy2BulletData->Enemy2Bullet->SetState(new Enemy2BulletDieState(this->enemy2BulletData));
		
	
}



BulletState::StateName Enemy2BulletMovingState::GetState()
{
    return BulletState::Moving;
}
