
#include "Boss3DieState.h"
#include "Boss3.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../GameComponents/Sound.h"
Boss3DieState::Boss3DieState(Boss3Data *playerData)
{
    this->mBoss3Data = playerData;
    this->mBoss3Data->Boss3->SetVx(0);
	this->mBoss3Data->Boss3->SetVy(0);
	this->mBoss3Data->Boss3->isDestroyed = true;
	dem = 0;
	Sound::getInstance()->play("BossExplosion", false, 1);
}


Boss3DieState::~Boss3DieState()
{
}

void Boss3DieState::Update(float dt)
{
	
}



Boss3DieState::StateName Boss3DieState::GetState()
{
    return Boss3DieState::Die;
}
