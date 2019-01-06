#include "Enemy3Bullet.h"

//#include "../../Enemy/Enemy3.h"
Enemy3Bullet::Enemy3Bullet()
{
	BulletMoving = new Animation("Resources/Bullets/Enemy2Bullet.png", 1, 1, 1, 0.2f);
	BulletDie = new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	damage = 1;
	//this->Enemy3BulletData = new Enemy3BulletData();
	this->enemy3BulletData = new Enemy3BulletData();
	this->enemy3BulletData->Enemy3Bullet = this;


	this->SetVx(0);
	this->SetVy(0);
	this->isDestroyed = false;

	this->SetState(new Enemy3BulletMovingState(this->enemy3BulletData));
}
Enemy3Bullet::~Enemy3Bullet()
{	
	//delete this->Enemy3BulletData;
}
void Enemy3Bullet::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->Enemy3Shot->Update(dt);
	if (this->enemy3BulletData->Enemy3BulletState)
	{
		this->enemy3BulletData->Enemy3BulletState->Update(dt);
	}
	
	
	
}







void Enemy3Bullet::SetState(BulletState *newState)
{
	delete this->enemy3BulletData->Enemy3BulletState;

	this->enemy3BulletData->Enemy3BulletState = newState;

	this->changeAnimation(newState->GetState()); 

	mCurrentState = newState->GetState();
}
Entity* Enemy3Bullet::getEntity()
{
	Entity *temp = new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}