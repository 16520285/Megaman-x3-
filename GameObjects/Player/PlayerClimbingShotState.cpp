#include "PlayerClimbingShotState.h"
#include "PlayerStandingState.h"
#include "Player.h"
#include "PlayerFallingState.h"
#include "PlayerSurfingState .h"
#include "PlayerClimbingState .h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
PlayerClimbingShotState::PlayerClimbingShotState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
	
}


PlayerClimbingShotState::~PlayerClimbingShotState()
{
}

void PlayerClimbingShotState::Update(float dt)
{

}

void PlayerClimbingShotState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[0x58]);
	else
	{
		this->mPlayerData->player->SetState(new PlayerClimbingState(this->mPlayerData));
	}
}

PlayerState::StateName PlayerClimbingShotState::GetState()
{
    return PlayerState::ClimbingShot;
}
