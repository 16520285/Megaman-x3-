#include "DoorStandingState.h"


#include "Door.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
DoorStandingState::DoorStandingState(DoorData *playerData)
{
	this->mDoorData = playerData;
}


DoorStandingState::~DoorStandingState()
{
}

void DoorStandingState::Update(float dt)
{
	if (this->mDoorData->Door->isOpen) this->mDoorData->Door->SetState(new DoorOpenState(this->mDoorData));
	
}



DoorState::StateName DoorStandingState::GetState()
{
	return DoorState::Standing;
}
