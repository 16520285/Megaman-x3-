
#include "Enemy3DieState.h"
#include "Enemy3.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../GameComponents/Sound.h"
Enemy3DieState::Enemy3DieState(Enemy3Data *playerData)
{
    this->mEnemyData3 = playerData;
    this->mEnemyData3->Enemy3->SetVx(0);
	this->mEnemyData3->Enemy3->isDestroyed = true;
	Sound::getInstance()->play("Explosion", false, 1);
}


Enemy3DieState::~Enemy3DieState()
{
}

void Enemy3DieState::Update(float dt)
{
	
	dem++;
	if (dem == 25) this->mEnemyData3->Enemy3->isDeleted = true;
	
}



Enemy3DieState::StateName Enemy3DieState::GetState()
{
    return Enemy3DieState::Die;
}
