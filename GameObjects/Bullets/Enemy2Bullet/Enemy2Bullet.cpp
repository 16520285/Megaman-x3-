#include "Enemy2Bullet.h"

//#include "../../Enemy/Enemy2.h"
Enemy2Bullet::Enemy2Bullet()
{
	BulletMoving = new Animation("Resources/Bullets/Enemy2Bullet.png", 1, 1, 1, 0.2f);
	BulletDie = new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	damage = 1;
	//this->Enemy2BulletData = new Enemy2BulletData();
	this->enemy2BulletData = new Enemy2BulletData();
	this->enemy2BulletData->Enemy2Bullet = this;


	this->SetVx(0);
	this->SetVy(0);
	this->isDestroyed = false;

	this->SetState(new Enemy2BulletMovingState(this->enemy2BulletData));
}
Enemy2Bullet::~Enemy2Bullet()
{	
	//delete this->Enemy2BulletData;
}
void Enemy2Bullet::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->Enemy2Shot->Update(dt);
	if (this->enemy2BulletData->Enemy2BulletState)
	{
		this->enemy2BulletData->Enemy2BulletState->Update(dt);
	}
	
	
	
}







void Enemy2Bullet::SetState(BulletState *newState)
{
	delete this->enemy2BulletData->Enemy2BulletState;

	this->enemy2BulletData->Enemy2BulletState = newState;

	this->changeAnimation(newState->GetState()); 

	mCurrentState = newState->GetState();
}
Entity* Enemy2Bullet::getEntity()
{
	Entity *temp = new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}