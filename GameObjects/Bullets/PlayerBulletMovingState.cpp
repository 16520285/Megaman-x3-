#include "PlayerBulletMovingState.h"
#include "PlayerBullet.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
PlayerBulletMovingState::PlayerBulletMovingState(PlayerBulletData *playerData)
{
    this->playerBulletData = playerData;
	
   
   
	count = 0;
	time = 70;
}


PlayerBulletMovingState::~PlayerBulletMovingState()
{

}

void PlayerBulletMovingState::Update(float dt)
{
	
		if (this->playerBulletData->PlayerBullet->mCurrentReverse) 	this->playerBulletData->PlayerBullet->SetVx(-Define::PLAYER_BULLET_VELOCITY);
		else this->playerBulletData->PlayerBullet->SetVx(Define::PLAYER_BULLET_VELOCITY);
		count++;
		if (count == time || this->playerBulletData->PlayerBullet->isDestroyed) this->playerBulletData->PlayerBullet->SetState(new PlayerBulletDieState(this->playerBulletData));
	
	
}



BulletState::StateName PlayerBulletMovingState::GetState()
{
    return BulletState::Moving;
}
