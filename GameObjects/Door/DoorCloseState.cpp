
#include "DoorCloseState.h"
#include "Door.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
DoorCloseState::DoorCloseState(DoorData *playerData)
{
    this->mDoorData = playerData;
	count = 0;
	time = 170;
	
}


DoorCloseState::~DoorCloseState()
{
}

void DoorCloseState::Update(float dt)
{
	count++;
	if (count==time) this->mDoorData->Door->SetState(new DoorClosedState(this->mDoorData));

	
	
}



DoorCloseState::StateName DoorCloseState::GetState()
{
    return DoorCloseState::Close;
}
