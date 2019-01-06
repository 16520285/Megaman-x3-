
#include "BeeDieState.h"
#include "Bee.h"
//#include "PlayerFallingState.h"
#include "../../../GameComponents/GameLog.h"
#include "../../../GameDefines/GameDefine.h"
#include "dinput.h"
BeeDieState::BeeDieState(BeeData *playerData)
{
    this->mBeeData = playerData;
    this->mBeeData->Bee->SetVx(0);
	this->mBeeData->Bee->isDestroyed = true;
	
}


BeeDieState::~BeeDieState()
{
}

void BeeDieState::Update(float dt)
{
	
	dem++;
	if (dem == 25)
		this->mBeeData->Bee->isDeleted = true;
	
}



BeeDieState::StateName BeeDieState::GetState()
{
    return BeeDieState::Die;
}
