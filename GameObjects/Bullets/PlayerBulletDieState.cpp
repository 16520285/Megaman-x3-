
#include "PlayerBulletDieState.h"
#include "PlayerBullet.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
PlayerBulletDieState::PlayerBulletDieState(PlayerBulletData *playerData)
{
    this->playerBulletData = playerData;
    this->playerBulletData->PlayerBullet->SetVx(0);
	this->playerBulletData->PlayerBullet->isDestroyed = true;
	this->playerBulletData->PlayerBullet->damage = 0;
	count = 0;
	
}


PlayerBulletDieState::~PlayerBulletDieState()
{
}

void PlayerBulletDieState::Update(float dt)
{
	count++;
	if (count == 15) this->playerBulletData->PlayerBullet->isDeleted = true;
	
}



BulletState::StateName PlayerBulletDieState::GetState()
{
    return BulletState::Die;
}
