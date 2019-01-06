
#include "Boss1DieState.h"
#include "Boss1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../GameComponents/Sound.h"
Boss1DieState::Boss1DieState(Boss1Data *playerData)
{
    this->mBoss1Data = playerData;
    this->mBoss1Data->Boss1->SetVx(0);
	this->mBoss1Data->Boss1->isDestroyed = true;
	dem = 0;
	Sound::getInstance()->play("BossExplosion", false, 1);
}


Boss1DieState::~Boss1DieState()
{
}

void Boss1DieState::Update(float dt)
{
	
	dem++;
	if (dem == 50) this->mBoss1Data->Boss1->isDeleted = true;
	
}



Boss1DieState::StateName Boss1DieState::GetState()
{
    return Boss1DieState::Die;
}
