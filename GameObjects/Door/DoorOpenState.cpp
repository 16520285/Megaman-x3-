#include "DoorOpenState.h"


#include "Door.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
DoorOpenState::DoorOpenState(DoorData *playerData)
{
	this->mDoorData = playerData;
	count = 0;
	time = 170;
}


DoorOpenState::~DoorOpenState()
{
}

void DoorOpenState::Update(float dt)
{
	
		

	count++;
	if (count == time) {
		this->mDoorData->Door->SetState(new DoorOpenedState(this->mDoorData));
	}
	

	
}



DoorState::StateName DoorOpenState::GetState()
{
	return DoorState::Open;
}
