
#include "EnemyDieState.h"
#include "Enemy1.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../GameComponents/Sound.h"
EnemyDieState::EnemyDieState(EnemyData1 *playerData)
{
    this->mEnemyData1 = playerData;
    this->mEnemyData1->Enemy1->SetVx(0);
	this->mEnemyData1->Enemy1->isDestroyed = true;
	Sound::getInstance()->play("Explosion", false, 1);
}


EnemyDieState::~EnemyDieState()
{
}

void EnemyDieState::Update(float dt)
{
	
	dem++;
	if (dem == 25) this->mEnemyData1->Enemy1->isDeleted = true;
	
}



EnemyDieState::StateName EnemyDieState::GetState()
{
    return EnemyDieState::Die;
}
