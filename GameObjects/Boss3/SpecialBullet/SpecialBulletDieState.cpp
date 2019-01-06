
#include "SpecialBulletDieState.h"
#include "SpecialBullet.h"
//#include "PlayerFallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../../GameComponents/Sound.h"
SpecialBulletDieState::SpecialBulletDieState(SpecialBulletData *playerData)
{
    this->mSpecialBulletData = playerData;
  
	this->mSpecialBulletData->SpecialBullet->isDestroyed = true;
	Sound::getInstance()->play("Explosion", false, 1);
	
}


SpecialBulletDieState::~SpecialBulletDieState()
{
}

void SpecialBulletDieState::Update(float dt)
{
	
	dem++;
	if (dem == 25)
		this->mSpecialBulletData->SpecialBullet->isDeleted = true;
	
}



SpecialBulletDieState::StateName SpecialBulletDieState::GetState()
{
    return SpecialBulletDieState::Die;
}
