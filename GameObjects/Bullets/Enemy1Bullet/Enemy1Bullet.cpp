#include "Enemy1Bullet.h"

//#include "../../Enemy/Enemy1.h"
Enemy1Bullet::Enemy1Bullet()
{
	BulletMoving = new Animation("Resources/Bullets/Enemy1Bullet.png", 1, 1, 1, 0.2f);
	BulletDie = new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	damage = 1;
	//this->Enemy1BulletData = new Enemy1BulletData();
	this->enemy1BulletData = new Enemy1BulletData();
	this->enemy1BulletData->Enemy1Bullet = this;


	this->SetVx(0);
	this->SetVy(0);
	this->isDestroyed = false;

	this->SetState(new Enemy1BulletMovingState(this->enemy1BulletData));
}
Enemy1Bullet::~Enemy1Bullet()
{	
	//delete this->Enemy1BulletData;
}
void Enemy1Bullet::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->Enemy1Shot->Update(dt);
	if (this->enemy1BulletData->Enemy1BulletState)
	{
		this->enemy1BulletData->Enemy1BulletState->Update(dt);
	}
	
	
	
}







void Enemy1Bullet::SetState(BulletState *newState)
{
	delete this->enemy1BulletData->Enemy1BulletState;

	this->enemy1BulletData->Enemy1BulletState = newState;

	this->changeAnimation(newState->GetState()); 

	mCurrentState = newState->GetState();
}
Entity* Enemy1Bullet::getEntity()
{
	Entity *temp = new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}