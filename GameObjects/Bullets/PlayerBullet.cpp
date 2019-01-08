#include "PlayerBullet.h"
#include "../../GameObjects/Player/Player.h"


PlayerBullet::PlayerBullet(int level) {
	if (level == 1)
	{
		BulletMoving = new Animation("Resources/Bullets/PlayerBulletMoving.png", 1, 1, 1, 0.2f);
		BulletDie = new Animation("Resources/Bullets/PlayerBulletDie.png", 3, 1, 3, 0.05f);
		damage = 1;
	}
	if (level == 2)
	{
		BulletMoving = new Animation("Resources/Bullets/PlayerBulletCharged1Moving.png", 1, 1, 1, 0.2f);
		BulletDie = new Animation("Resources/Bullets/PlayerBulletCharged1Die.png", 4, 1, 4, 0.05f);
		damage = 2;
	}
	if (level == 3)
	{
		BulletMoving = new Animation("Resources/Bullets/PlayerBulletCharged2Moving.png", 1, 1, 1, 0.2f);
		BulletDie = new Animation("Resources/Bullets/PlayerBulletCharged2Die.png", 4, 1, 4, 0.05f);
		damage = 5;
	}
	//this->playerBulletData = new EnemyData3();
	//this->playerBulletData->PlayerBullet = this;
	this->playerBulletData = new PlayerBulletData();
	this->playerBulletData->PlayerBullet = this;
	
	this->SetVx(0);
	this->SetVy(0);
	this->isDestroyed = false;
	
	this->SetState(new PlayerBulletMovingState(this->playerBulletData));
	//this->SetState(new BulletMovingState(this->playerBulletData));
	//this->mEnemyData->PlayerShot = new PlayerShot(this);
	
	
}
PlayerBullet::PlayerBullet()
{
}
PlayerBullet::~PlayerBullet()
{	
	//delete this->playerBulletData;
}
void PlayerBullet::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->PlayerShot->Update(dt);
	if (this->playerBulletData->PlayerBulletState)
	{
		this->playerBulletData->PlayerBulletState->Update(dt);
	}
	
	
	
}







void PlayerBullet::SetState(BulletState *newState)
{
	delete this->playerBulletData->PlayerBulletState;

	this->playerBulletData->PlayerBulletState = newState;

	this->changeAnimation(newState->GetState()); 

	mCurrentState = newState->GetState();
}
