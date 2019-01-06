#include "DoorOpenedState.h"


#include "Door.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
DoorOpenedState::DoorOpenedState(DoorData *playerData)
{
	this->mDoorData = playerData;
	
}


DoorOpenedState::~DoorOpenedState()
{
}

void DoorOpenedState::Update(float dt)
{
	this->mDoorData->Door->SetWidth(0);
	this->mDoorData->Door->SetHeight(0);
	
	
	if (this->mDoorData->Door->locked) this->mDoorData->Door->SetState(new DoorCloseState(this->mDoorData));
	
}



DoorState::StateName DoorOpenedState::GetState()
{
	return DoorState::Opened;
}
