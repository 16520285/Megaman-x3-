#include "Enemy3FlyingState.h"
#include "Enemy3StandingState.h"

#include "../../GameDefines/GameDefine.h"
#include "../../GameComponents/GameLog.h"

Enemy3FlyingState::Enemy3FlyingState(Enemy3Data *playerData)
{
    this->mEnemyData3 = playerData;
   this->mEnemyData3->Enemy3->SetVy(Define::ENEMY3_FLY_VELOCITY);

    acceleratorY = -5.0f;
   // if (this->mEnemyData3->Enemy3->mCurrentReverse) acceleratorX = 10.0f;
	//else acceleratorX = -10.0f;
	    noPressed = false;
}


Enemy3FlyingState::~Enemy3FlyingState()
{

}

void Enemy3FlyingState::Update(float dt)
{
	
	if (mEnemyData3->Enemy3->GetVy() > 0)
	{
		this->mEnemyData3->Enemy3->AddVy(acceleratorY);
		
		
	}
	
	else  mEnemyData3->Enemy3->SetState(new Enemy3ShootingState(this->mEnemyData3));
   

 
}

void Enemy3FlyingState::OnCollision(Entity *impactor, Entity::SideCollisions side, Entity::CollisionReturn data)
{
	switch (side)
	{
	case Entity::Left:
	{
		this->mEnemyData3->Enemy3->AddPosition(data.RegionCollision.right - data.RegionCollision.left, 0);
		this->mEnemyData3->Enemy3->SetVx(0);
		break;
	}

	case Entity::Right:
	{
		this->mEnemyData3->Enemy3->AddPosition(-(data.RegionCollision.right - data.RegionCollision.left), 0);
		this->mEnemyData3->Enemy3->SetVx(0);
		break;
	}

	case Entity::TopRight: case Entity::TopLeft: case Entity::Top:
	{
		this->mEnemyData3->Enemy3->AddPosition(0, data.RegionCollision.bottom - data.RegionCollision.top);
		this->mEnemyData3->Enemy3 ->SetVy(0);
		break;
	}

	case Entity::BottomRight: case Entity::BottomLeft: case Entity::Bottom:
	{
		this->mEnemyData3->Enemy3->AddPosition(0, -(data.RegionCollision.bottom - data.RegionCollision.top));
	}

	default:
		break;
	}
}


Enemy3State::StateName Enemy3FlyingState::GetState()
{
    return Enemy3State::Flying;
}
