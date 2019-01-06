#include "Enemy3BulletMovingState.h"
#include "Enemy3Bullet.h"
//#include "Enemy3FallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy3BulletMovingState::Enemy3BulletMovingState(Enemy3BulletData *Enemy3Data)
{
    this->enemy3BulletData = Enemy3Data;
	
	
	count = 0;
	time = 200;
}


Enemy3BulletMovingState::~Enemy3BulletMovingState()
{

}

void Enemy3BulletMovingState::Update(float dt)
{
		if (this->enemy3BulletData->Enemy3Bullet->mCurrentReverse) this->enemy3BulletData->Enemy3Bullet->SetVx(Define::ENEMY3_BULLET_VELOCITY);
		else this->enemy3BulletData->Enemy3Bullet->SetVx(-Define::ENEMY3_BULLET_VELOCITY);
		count++;
		if (count == time || this->enemy3BulletData->Enemy3Bullet->isDestroyed) this->enemy3BulletData->Enemy3Bullet->SetState(new Enemy3BulletDieState(this->enemy3BulletData));
		
	
}



BulletState::StateName Enemy3BulletMovingState::GetState()
{
    return BulletState::Moving;
}
