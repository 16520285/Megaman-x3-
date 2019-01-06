#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerClimbingState .h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
PlayerClimbingState::PlayerClimbingState(PlayerData *playerData)
{
	this->mPlayerData = playerData;

	acceleratorX = 8.0f;
	acceleratorY = 1.0f;
}


PlayerClimbingState::~PlayerClimbingState()
{
}

void PlayerClimbingState::Update(float dt)
{
	//this->mPlayerData->player->AddVx(acceleratorX);

	/*if (mPlayerData->player->GetVx() >= 0)
	{
		mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));

		return;
	}*/
}

void PlayerClimbingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_UP])
	{
		mPlayerData->player->SetReverse(false);
		this->mPlayerData->player->AddVy(-acceleratorY);
	}
	else if (keys[VK_DOWN])
	{
		mPlayerData->player->SetReverse(false);
		this->mPlayerData->player->AddVy(acceleratorY);
	}
	else 
	{
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		//return;
	}
	if (keys[0x58] )
	{
		mPlayerData->player->SetReverse(false);
		this->mPlayerData->player->SetState(new PlayerClimbingShotState(this->mPlayerData));
	}
}

PlayerState::StateName PlayerClimbingState::GetState()
{
	return PlayerState::Climbing;
}
