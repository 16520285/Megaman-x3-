#include "PlayerWallState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerJumpingState.h"
#include "PlayerWallShotState.h"
#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

PlayerWallState::PlayerWallState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY*2);

    acceleratorY = 5.0f;
    acceleratorX = 2.0f;
	noPressed = false;
}


PlayerWallState::~PlayerWallState()
{

}

void PlayerWallState::Update(float dt)
{
    this->mPlayerData->player->SetVy(acceleratorY*3); 
	//GAMELOG("vy: %d", mPlayerData->player->GetVy());

    
   
	
}

void PlayerWallState::HandleKeyboard(std::map<int, bool> keys)
{
    if (keys[VK_RIGHT] && !keys[VK_SPACE] && !(this->mPlayerData->player->mCurrentReverse) && !keys[0x58])
    {
        mPlayerData->player->SetReverse(false);

        //di chuyen sang phai
		this->mPlayerData->player->SetVy(acceleratorY * 3);

        noPressed = false;
    }
    else if (keys[VK_LEFT] && !keys[VK_SPACE] && (this->mPlayerData->player->mCurrentReverse) && !keys[0x58])
    {
        mPlayerData->player->SetReverse(true);

        //di chuyen sang trai
		this->mPlayerData->player->SetVy(acceleratorY * 3);

        noPressed = false;
    }
	else if (keys[VK_SPACE] && (keys[VK_RIGHT] || keys[VK_LEFT]))
	{
		
		this->mPlayerData->player->SetState(new PlayerJumpingState(this->mPlayerData));
	}
	else if (keys[0x58] && keys[VK_RIGHT] && !keys[VK_SPACE] && !(this->mPlayerData->player->mCurrentReverse))
	{
		this->mPlayerData->player->SetState(new PlayerWallShotState(this->mPlayerData));
	}
	else if (keys[0x58] && keys[VK_LEFT] && !keys[VK_SPACE] && (this->mPlayerData->player->mCurrentReverse))
	{
		this->mPlayerData->player->SetState(new PlayerWallShotState(this->mPlayerData));
	}
	else 
    {
        noPressed = true;
		this->mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));
    }
}

void PlayerWallState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
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

PlayerState::StateName PlayerWallState::GetState()
{
    return PlayerState::Walling;
}
