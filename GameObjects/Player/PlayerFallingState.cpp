#include "PlayerFallingState.h"
#include "Player.h"
#include "PlayerStandingState.h"
#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"
#include "PlayerWallState.h"
PlayerFallingState::PlayerFallingState(PlayerData *playerData)
{
    this->mPlayerData = playerData;
    acceleratorY = 5.0f;
    acceleratorX = 3.0f;

    if (this->mPlayerData->player->GetVx() == 0)
    {
        allowMoveX = false;
    }
    else
    {
        allowMoveX = true;
    }
}


PlayerFallingState::~PlayerFallingState()
{
}

void PlayerFallingState::Update(float dt)
{
   /* this->mPlayerData->player->AddVy(acceleratorY);

    if (mPlayerData->player->GetVy() > Define::PLAYER_MAX_JUMP_VELOCITY)
    {
        mPlayerData->player->SetVy(Define::PLAYER_MAX_JUMP_VELOCITY);
    }*/
	this->mPlayerData->player->SetVy(acceleratorY * 80);
}

void PlayerFallingState::HandleKeyboard(std::map<int, bool> keys)
{
    if (keys[VK_RIGHT])
    {
        mPlayerData->player->SetReverse(false);

        isLeftOrRightKeyPressed = true;
        //di chuyen sang phai
		this->mPlayerData->player->SetVx(acceleratorX * 100);
    }
    else if (keys[VK_LEFT])
    {
        mPlayerData->player->SetReverse(true);

        isLeftOrRightKeyPressed = true;
        //di chuyen sang trai
		this->mPlayerData->player->SetVx(-acceleratorX * 100);
    }
    else
    {
        isLeftOrRightKeyPressed = false;    
    }
}
void PlayerFallingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);

	switch (side)
	{
	case Entity::Left:
		if (mPlayerData->player->getMoveDirection() == Player::MoveToLeft)
		{
			this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
			this->mPlayerData->player->SetVx(0);
			//this->mPlayerData->player->SetReverse(true);
			this->mPlayerData->player->SetState(new PlayerWallState(this->mPlayerData));
		}
		break;

	case Entity::Right:
		if (mPlayerData->player->getMoveDirection() == Player::MoveToRight)
		{
			this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
			this->mPlayerData->player->SetVx(0);
			this->mPlayerData->player->SetState(new PlayerWallState(this->mPlayerData));
		}
		break;

	case Entity::Top:
		break;

	case Entity::Bottom:
	case Entity::BottomRight:
	case Entity::BottomLeft:
		if (data.RegionCollision.right - data.RegionCollision.left >= 8.0f)
		{
			
			//GAMELOG("posy+1: %d", data.RegionCollision.right);
			//this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));
			
			this->mPlayerData->player->AddPosition(0,4 );
		
			
			if (isLeftOrRightKeyPressed)
			{
				this->mPlayerData->player->SetState(new PlayerRunningState(this->mPlayerData));
			}
			else
			{
				this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
			}
			
		}
		return;

	default:
		break;
	}
}


PlayerState::StateName PlayerFallingState::GetState()
{
    return PlayerState::Falling;
}
