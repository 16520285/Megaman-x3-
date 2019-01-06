
#include "PlayerDieState.h"
#include "Player.h"
//#include "PlayerFallingState.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
PlayerDieState::PlayerDieState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    this->mPlayerData->player->SetVx(0);
	this->mPlayerData->player->SetVy(0);
	this->mPlayerData->player->nobody = true;
}


PlayerDieState::~PlayerDieState()
{
}

void PlayerDieState::Update(float dt)
{
	
	
	
}



PlayerDieState::StateName PlayerDieState::GetState()
{
    return PlayerDieState::Die;
}
