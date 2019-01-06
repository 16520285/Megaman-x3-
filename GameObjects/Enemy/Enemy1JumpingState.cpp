#include "Enemy1JumpingState.h"
#include "Enemy1StandingState.h"

#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

Enemy1JumpingState::Enemy1JumpingState(EnemyData1 *playerData)
{
    this->mEnemyData1 = playerData;
    this->mEnemyData1->Enemy1->SetVy(Define::ENEMY1_JUMP_VELOCITY);
	this->mEnemyData1->Enemy1->timeshot = 0;
	if (this->mEnemyData1->Enemy1->mCurrentReverse) acceleratorX = 50.0f;
	else acceleratorX = -50.0f;
	acceleratorY = 5.0f;
	    noPressed = false;
}


Enemy1JumpingState::~Enemy1JumpingState()
{

}

void Enemy1JumpingState::Update(float dt)
{
	if (mEnemyData1->Enemy1->GetVy() < 0)
	{
		this->mEnemyData1->Enemy1->AddVy(acceleratorY);
		this->mEnemyData1->Enemy1->SetVx(acceleratorX);
		
		
	}
	else  mEnemyData1->Enemy1->SetState(new Enemy1FallingState(this->mEnemyData1));
   

 
}

void Enemy1JumpingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	switch (side)
	{
	case Entity::Left:
	{
		this->mEnemyData1->Enemy1->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
		this->mEnemyData1->Enemy1->SetVx(0);
		break;
	}

	case Entity::Right:
	{
		this->mEnemyData1->Enemy1->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
		this->mEnemyData1->Enemy1->SetVx(0);
		break;
	}

	case Entity::TopRight: case Entity::TopLeft: case Entity::Top:
	{
		this->mEnemyData1->Enemy1->AddPosition(0, data.RegionCollision.bottom - data.RegionCollision.top);
		//this->mEnemyData1->Enemy1 ->SetVy(0);
		break;
	}

	case Entity::BottomRight: case Entity::BottomLeft: case Entity::Bottom:
	{
		this->mEnemyData1->Enemy1->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));
		//this->mEnemyData1->Enemy1->SetState(new Enemy1StandingState(this->mEnemyData1));
	}

	default:
		break;
	}
}


Enemy1State::StateName Enemy1JumpingState::GetState()
{
    return Enemy1State::Jumping;
}
