#include "PlayerRunningState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "PlayerSurfingShotState .h"
#include "PlayerSurfingState .h"
#include "../../GameDefines/GameDefine.h"
#include "dinput.h"
PlayerSurfingShotState::PlayerSurfingShotState(PlayerData *playerData)
{
	this->mPlayerData = playerData;

	acceleratorX = 8.0f;
}


PlayerSurfingShotState::~PlayerSurfingShotState()
{
}

void PlayerSurfingShotState::Update(float dt)
{
	this->mPlayerData->player->AddVx(acceleratorX);

	
}

void PlayerSurfingShotState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[0x5A] && keys[0x43])
	{
		//mPlayerData->player->SetReverse(false);
		if (this->mPlayerData->player->mCurrentReverse) mPlayerData->player->SetVx(-acceleratorX * 80);
		else  mPlayerData->player->SetVx(acceleratorX * 80);
	}
	else
	if (!keys[0x43] && keys[0x5A])
	{
		this->mPlayerData->player->SetState(new PlayerSurfingState(this->mPlayerData));
		return;
	}
	else
	{
		this->mPlayerData->player->SetState(new PlayerStandingState(this->mPlayerData));
		return;
	}

	
}
void PlayerSurfingShotState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
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

			//this->mPlayerData->player->SetState(new PlayerSurfingState(this->mPlayerData));
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
			//this->mPlayerData->player->SetState(new  PlayerSurfingState(this->mPlayerData));
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
PlayerState::StateName PlayerSurfingShotState::GetState()
{
	return PlayerState::SurfingShot;
}
