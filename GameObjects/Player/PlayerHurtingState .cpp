#include "PlayerStandingState.h"
#include "Player.h"
#include "PlayerHurtingState .h"
#include "PlayerSurfingState .h"
#include "PlayerClimbingState .h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
#include "../../GameComponents/GameLog.h"
PlayerHurtingState::PlayerHurtingState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
	//GAMELOG("a:%d", this->mPlayerData->player->getMoveDirection());
	//if (this->mPlayerData->player->mCurrentReverse)  this->mPlayerData->player->SetVx(30);
	//else this->mPlayerData->player->SetVx(-30);
	this->mPlayerData->player->SetVx(0);
    this->mPlayerData->player->SetVy(0);
	isHurting=1;
	count = 0;
	timeHurting = 30;
	this->mPlayerData->player->nobody = true;
	this->mPlayerData->player->HP = this->mPlayerData->player->HP - 2;
}


PlayerHurtingState::~PlayerHurtingState()
{
}

void PlayerHurtingState::Update(float dt)
{
	count++;
	if (count == timeHurting)
		this->mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
}

void PlayerHurtingState::HandleKeyboard(std::map<int, bool> keys)
{
    
}

PlayerState::StateName PlayerHurtingState::GetState()
{
    return PlayerState::Hurting;
}
