#include "PlayerJumpingState.h"
#include "PlayerStandingState.h"
#include "PlayerFallingState.h"
#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

PlayerJumpingState::PlayerJumpingState(PlayerData *playerData)
{
	this->mPlayerData = playerData;
	this->mPlayerData->player->SetVy(Define::PLAYER_MIN_JUMP_VELOCITY*2.8);

	acceleratorY = 6.0f;
	acceleratorX = 2.0f;
	noPressed = false;
}


PlayerJumpingState::~PlayerJumpingState()
{

}

void PlayerJumpingState::Update(float dt)
{
	this->mPlayerData->player->AddVy(acceleratorY * 5);


	if (mPlayerData->player->GetVy() >= 0)
	{
		mPlayerData->player->SetState(new PlayerFallingState(this->mPlayerData));

		return;
	}

	

}

void PlayerJumpingState::HandleKeyboard(std::map<int, bool> keys)
{
	if (keys[VK_RIGHT])
	{
		mPlayerData->player->SetReverse(false);

		//di chuyen sang phai
		this->mPlayerData->player->SetVx(acceleratorX * 130);

		noPressed = false;
	}
	else if (keys[VK_LEFT])
	{
		mPlayerData->player->SetReverse(true);

		//di chuyen sang trai
		this->mPlayerData->player->SetVx(-acceleratorX * 130);

		noPressed = false;
	}
	else
	{
		noPressed = true;
	}
}

void PlayerJumpingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
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

PlayerState::StateName PlayerJumpingState::GetState()
{
	return PlayerState::Jumping;
}
