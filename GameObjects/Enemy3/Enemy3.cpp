#include "Enemy3.h"
#include "../../GameObjects/Player/Player.h"


Enemy3::Enemy3() {
	
	Enemy3Standing = new Animation("Resources/enemy3/Enemy3Standing.png", 5, 1, 5, 0.2f);
	Enemy3Flying = new Animation("Resources/enemy3/Enemy3Flying.png", 5, 1, 5, 0.2f);
	Enemy3Die = new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	Enemy3Shooting = new Animation("Resources/enemy3/Enemy3Shooting.png", 5, 1, 5, 0.05f);
	//this->mEnemyData3 = new EnemyData3();
	//this->mEnemyData3->Enemy3 = this;
	this->mEnemyData3 = new Enemy3Data();
	this->mEnemyData3->Enemy3 = this;
	
	this->SetVx(0);
	this->SetVy(0);
	
	
	this->SetState(new Enemy3StandingState(this->mEnemyData3));
	//this->SetState(new Enemy3StandingState(this->mEnemyData3));
	//this->mEnemyData->PlayerShot = new PlayerShot(this);
	
	HP = 5;
}
Enemy3::~Enemy3()
{	
}
void Enemy3::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->PlayerShot->Update(dt);
	if (isDestroyed && mCurrentState != 3) this->SetState(new Enemy3DieState(this->mEnemyData3));
	if (this->mEnemyData3->Enemy3State)
	{
		this->mEnemyData3->Enemy3State->Update(dt);
	}
	
	
	
}


void Enemy3::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Enemy3::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);
	
	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
	
	
}

void Enemy3::changeAnimation(Enemy3State::StateName state)
{
	switch (state)
	{
	case Enemy3State::Standing:
		CurrentAnimation = Enemy3Standing;
		break;
	case Enemy3State::Flying:
		CurrentAnimation = Enemy3Flying;
		break;
	
	case Enemy3State::Shooting:
		CurrentAnimation = Enemy3Shooting;
		break;
	case Enemy3State::Die:
		CurrentAnimation = Enemy3Die;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Enemy3::SetState(Enemy3State *newState)
{
	delete this->mEnemyData3->Enemy3State;

	this->mEnemyData3->Enemy3State = newState;

	this->changeAnimation(newState->GetState()); 

	mCurrentState = newState->GetState();
}
Enemy3State::StateName Enemy3::getState()
{
	return mCurrentState;
}
void Enemy3::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mEnemyData3->Enemy3State->OnCollision(impactor, side, data);
}
Entity* Enemy3::getEntity()
{
	Entity *temp = new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}
void Enemy3::OnCollissionWithBullet(int damage)
{
	HP = HP - damage;
	if (HP < 0) isDestroyed = true;
}
void Enemy3::onFired()
{
	Enemy3Bullet *tempbullet = new Enemy3Bullet();
	if (this->mCurrentReverse) tempbullet->SetReverse(true);
	else tempbullet->SetReverse(false);
	tempbullet->SetPosition(this->GetPosition());
	mListEnemy3Bullet.push_back(tempbullet);

}