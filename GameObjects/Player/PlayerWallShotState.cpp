#include "PlayerWallShotState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpingState.h"
#include "PlayerWallState.h"
#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

PlayerWallShotState::PlayerWallShotState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY*2);

    acceleratorY = 5.0f;
    acceleratorX = 2.0f;
	noPressed = false;
}


PlayerWallShotState::~PlayerWallShotState()
{

}

void PlayerWallShotState::Update(float dt)
{
    this->mPlayerData->player->SetVy(acceleratorY*3); 
	//GAMELOG("vy: %d", mPlayerData->player->GetVy());

    
   
	
}

void PlayerWallShotState::HandleKeyboard(std::map<int, bool> keys)
{
    if (keys[VK_RIGHT] && !keys[VK_SPACE] && !(this->mPlayerData->player->mCurrentReverse))
    {
        mPlayerData->player->SetReverse(false);

        //di chuyen sang phai
		this->mPlayerData->player->SetVy(acceleratorY * 3);

        noPressed = false;
	
    }
    else if (keys[VK_LEFT] && !keys[VK_SPACE] && (this->mPlayerData->player->mCurrentReverse))
    {
        mPlayerData->player->SetReverse(true);

        //di chuyen sang trai
		this->mPlayerData->player->SetVy(acceleratorY * 3);

        noPressed = false;
		
    }
	else if (keys[VK_SPACE] && (keys[VK_RIGHT] || keys[VK_LEFT]))
	{
		GAMELOG("jump: %d", mPlayerData->player->allowJump);
		this->mPlayerData->player->SetState(new PlayerJumpingState(this->mPlayerData));
		return;
	}
	else 
    {
        noPressed = true;
		this->mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
		return;
    }


	if (keys[0x58]);
	else {
		this->mPlayerData->player->SetState(new PlayerWallState(this->mPlayerData));
		return;
	}
}

void PlayerWallShotState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	switch (side)
	{
	case Entity::Left:
	{
		this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
		this->mPlayerData->player->SetVx(0);
		break;
	}

	case Entity::Right:
	{
		this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
		this->mPlayerData->player->SetVx(0);
		break;
	}

	case Entity::TopRight: case Entity::TopLeft: case Entity::Top:
	{
		this->mPlayerData->player->AddPosition(0, data.RegionCollision.bottom - data.RegionCollision.top);
		this->mPlayerData->player->SetVy(0);
		break;
	}

	case Entity::BottomRight: case Entity::BottomLeft: case Entity::Bottom:
	{
		this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));
	}

	default:
		break;
	}
}

PlayerState::StateName PlayerWallShotState::GetState()
{
    return PlayerState::WallingShot;
}
