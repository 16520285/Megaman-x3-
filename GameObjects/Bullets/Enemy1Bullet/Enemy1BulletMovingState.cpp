#include "Enemy1BulletMovingState.h"
#include "Enemy1Bullet.h"
//#include "Enemy1FallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
Enemy1BulletMovingState::Enemy1BulletMovingState(Enemy1BulletData *Enemy1Data)
{
    this->enemy1BulletData = Enemy1Data;
	this->enemy1BulletData->Enemy1Bullet->SetVy(Define::ENEMY1_BULLET_VELOCITY);
   
   
	count = 0;
	time = 500;
}


Enemy1BulletMovingState::~Enemy1BulletMovingState()
{

}

void Enemy1BulletMovingState::Update(float dt)
{
	
		if (this->enemy1BulletData->Enemy1Bullet->mCurrentReverse) 	this->enemy1BulletData->Enemy1Bullet->SetVx(100.0f);
		else this->enemy1BulletData->Enemy1Bullet->SetVx(-100.0f);
		if (this->enemy1BulletData->Enemy1Bullet->GetVy() != -Define::ENEMY1_BULLET_VELOCITY)
		{
			this->enemy1BulletData->Enemy1Bullet->AddVy(10.0f);
		}
		else this->enemy1BulletData->Enemy1Bullet->SetState(new Enemy1BulletDieState(this->enemy1BulletData));
		
		
	


		
		count++;
		//if (count == time || this->enemy1BulletData->Enemy1Bullet->isDestroyed) this->enemy1BulletData->Enemy1Bullet->SetState(new Enemy1BulletDieState(this->enemy1BulletData));
		
	
}



BulletState::StateName Enemy1BulletMovingState::GetState()
{
    return BulletState::Moving;
}
