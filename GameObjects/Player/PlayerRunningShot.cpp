#include "PlayerRunningShot.h"
#include "PlayerStandingState.h"
#include "PlayerState.h"
#include "../../GameDefines/GameDefine.h"


PlayerRunningShotState::PlayerRunningShotState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	acceleratorX = 8.0f;
}


PlayerRunningShotState::PlayerRunningShotState()
{
}
void PlayerRunningShotState::Update(float dt)
{
}


void PlayerRunningShotState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT] && keys[0x43] )
		
	{
		mPlayerData->player->SetReverse(false);
		this->mPlayerData->player->SetVx(acceleratorX * 70);
	}
	else if (keys[VK_LEFT] && keys[0x43] )
			
	{
		mPlayerData->player->SetReverse(true);

		//di chuyen sang trai
		this->mPlayerData->player->SetVx(-acceleratorX * 70);
	}
	else
	{
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		return;
	}
}
void PlayerRunningShotState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	//lay phia va cham so voi player
	//GameCollision::SideCollisions side = GameCollision::getSideCollision(this->mPlayerData->player, data);

	switch (side)
	{
	case Entity::Left:
	{
		//va cham phia ben trai player
		if (this->mPlayerData->player->getMoveDirection() == Player::MoveToLeft)
		{
			this->mPlayerData->player->allowMoveLeft = false;

			//day Player ra phia ben phai de cho player khong bi xuyen qua object
			this->mPlayerData->player->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);

			this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		}

		return;
	}

	case Entity::Right:
	{
		//va cham phia ben phai player
		if (this->mPlayerData->player->getMoveDirection() == Player::MoveToRight)
		{
			this->mPlayerData->player->allowMoveRight = false;
			this->mPlayerData->player->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
			this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		}
		return;
	}

	case Entity::Top:
		break;

	case Entity::Bottom: case Entity::BottomLeft: case Entity::BottomRight:
	{
		this->mPlayerData->player->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));

		this->mPlayerData->player->SetVy(0);

		return;
	}
	}
}
PlayerState::StateName PlayerRunningShotState::GetState()
{
	return PlayerState::RunningShot;
}
