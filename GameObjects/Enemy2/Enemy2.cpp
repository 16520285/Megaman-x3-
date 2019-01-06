#include "Enemy2.h"
#include "../../GameObjects/Player/Player.h"


Enemy2::Enemy2() {

	Enemy2Standing = new Animation("Resources/enemy2/enemy2Standing.png", 2, 1, 2, 0.1f);
	Enemy2Shooting = new Animation("Resources/enemy2/enemy2Shooting.png", 4, 1, 4, 0.2f);
	Enemy2Die = new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	this->mEnemyData2 = new EnemyData2();
	this->mEnemyData2->Enemy2 = this;
	this->SetVx(0);
	this->SetVy(0);
	
	
	this->SetState(new Enemy2StandingState(this->mEnemyData2));
	//this->SetState(new Enemy2StandingState(this->mEnemyData1));
	//this->mEnemyData->PlayerShot = new PlayerShot(this);
	HP = 5;

}
Enemy2::~Enemy2()
{
}
void Enemy2::Update(float dt)
{

	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->mEnemyData->PlayerShot->Update(dt);
	if (isDestroyed && mCurrentState != 2) this->SetState(new Enemy2DieState(this->mEnemyData2));
	if (this->mEnemyData2->Enemy2State)
	{
		this->mEnemyData2->Enemy2State->Update(dt);
	}



}


void Enemy2::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Enemy2::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Enemy2::changeAnimation(Enemy2State::StateName state)
{
	switch (state)
	{
	case Enemy2State::Standing:
		CurrentAnimation = Enemy2Standing;
		break;
	case Enemy2State::Shooting:
		CurrentAnimation = Enemy2Shooting;
		break;
	case Enemy2State::Die:
		CurrentAnimation = Enemy2Die;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Enemy2::SetState(Enemy2State *newState)
{
	delete this->mEnemyData2->Enemy2State;

	this->mEnemyData2->Enemy2State = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
Enemy2State::StateName Enemy2::getState()
{
	return mCurrentState;
}
Entity* Enemy2::getEntity()
{
	Entity *temp = new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}
void Enemy2::OnCollissionWithBullet(int damage)
{
	HP = HP - damage;
	if (HP < 0) isDestroyed = true;
}
void Enemy2::onFired()
{
	Enemy2Bullet *tempbullet = new Enemy2Bullet();
	if (this->mCurrentReverse) tempbullet->SetReverse(true);
	else tempbullet->SetReverse(false);
	tempbullet->SetPosition(this->GetPosition());
	mListEnemy2Bullet.push_back(tempbullet);

}