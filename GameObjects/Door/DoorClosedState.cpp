#include "DoorClosedState.h"


#include "Door.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
DoorClosedState::DoorClosedState(DoorData *playerData)
{
	this->mDoorData = playerData;
	this->mDoorData->Door->SetWidth(45);
	this->mDoorData->Door->SetHeight(123);
}


DoorClosedState::~DoorClosedState()
{
}

void DoorClosedState::Update(float dt)
{
	
	
	

	
}



DoorState::StateName DoorClosedState::GetState()
{
	return DoorState::Closed;
}
