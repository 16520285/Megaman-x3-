#include "Enemy1.h"
#include "../../GameObjects/Player/Player.h"
#include "EnemyDieState.h"

Enemy1::Enemy1() {
	
	Enemy1Standing = new Animation("Resources/enemy1/enemy1Standing.png", 1, 1, 1, 0.0f);
	Enemy1Jumping = new Animation("Resources/enemy1/enemy1Jumping.png", 1, 1, 1, 0.0f);
	Enemy1Falling = new Animation("Resources/enemy1/enemy1Jumping.png", 1, 1, 1, 0.0f);
	Enemy1Shooting = new Animation("Resources/enemy1/enemy1Shooting.png", 1, 1, 1, 0.0f);
	Enemy1Die = new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	this->mEnemyData1 = new EnemyData1();
	this->mEnemyData1->Enemy1 = this;
	this->SetVx(0);
	this->SetVy(0);
	Enemy1Standing->SetScale(D3DXVECTOR2(2, 2));
	
	this->SetState(new Enemy1StandingState(this->mEnemyData1));
	//this->SetState(new Enemy1StandingState(this->mEnemyData1));
	//this->mEnemyData->PlayerShot = new PlayerShot(this);
	HP = 3; 
	
}
Enemy1::~Enemy1()
{	
}
void Enemy1::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->PlayerShot->Update(dt);
	if (isDestroyed && mCurrentState!=5) this->SetState(new EnemyDieState(this->mEnemyData1));
	if (this->mEnemyData1->Enemy1State)
	{
		this->mEnemyData1->Enemy1State->Update(dt);
	}
	
	
	
}


void Enemy1::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Enemy1::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);
	
	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
	
	
}

void Enemy1::changeAnimation(Enemy1State::StateName state)
{
	switch (state)
	{
	case Enemy1State::Standing:
		CurrentAnimation = Enemy1Standing;
		break;
	case Enemy1State::Jumping:
		CurrentAnimation = Enemy1Jumping;
		break;
	case Enemy1State::Falling:
		CurrentAnimation = Enemy1Falling;
		break;
	case Enemy1State::Shooting:
		CurrentAnimation = Enemy1Shooting;
		break;
	case Enemy1State::Die:
		CurrentAnimation = Enemy1Die;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Enemy1::SetState(Enemy1State *newState)
{
	delete this->mEnemyData1->Enemy1State;

	this->mEnemyData1->Enemy1State = newState;

	this->changeAnimation(newState->GetState()); 

	mCurrentState = newState->GetState();
}
Enemy1State::StateName Enemy1::getState()
{
	return mCurrentState;
}

void Enemy1::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mEnemyData1->Enemy1State->OnCollision(impactor, side, data);
}

Entity* Enemy1::getEntity()
{
	Entity *temp=new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}

void Enemy1::OnCollissionWithBullet(int damage)
{
	HP=HP-damage;
	if (HP <= 0) isDestroyed = true;
}

void Enemy1::onFired()
{
		Enemy1Bullet *tempbullet = new Enemy1Bullet();
		if (this->mCurrentReverse) tempbullet->SetReverse(true);
		else tempbullet->SetReverse(false);
		tempbullet->SetPosition(this->GetPosition());
		mListEnemy1Bullet.push_back(tempbullet);
		
}