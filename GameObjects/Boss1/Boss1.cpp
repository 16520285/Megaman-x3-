#include "Boss1.h"





Boss1::Boss1() {

	Boss1Standing = new Animation("Resources/Boss1/Boss1Standing2.png", 11, 1, 11, 0.001f);
	Boss1Moving = new Animation("Resources/Boss1/Boss1Moving.png", 1, 1, 1, 0.0f);
	Boss1Born= new Animation("Resources/Boss1/Boss1Standing.png", 10, 1, 10, 0.0f);
	Boss1Die = new Animation("Resources/Boss1/Explosion.png", 8, 1, 8, 0.2f);
	Boss1Horizontal =  new Animation("Resources/Boss1/Boss1Standing.png", 10, 1, 10, 0.0f);
	Boss1Born->SetScale(D3DXVECTOR2(2, 2));
	//this->mBoss1Data->Boss1 = this;
	Boss1Moving->SetScale(D3DXVECTOR2(2, 2));
	Boss1Standing->SetScale(D3DXVECTOR2(2, 2));
	this->mBoss1Data = new Boss1Data();
	this->mBoss1Data->Boss1 = this;
	Boss1Horizontal->SetScale(D3DXVECTOR2(2, 2));
	this->SetVx(0);
	this->SetVy(0);
	this->mBoss1Data->Boss1->SetVx(-100);
	this->SetState(new Boss1BornState(this->mBoss1Data));
	this->HP = 20;
	//this->SetState(new Boss1StandingState(this->mBoss1Data));
	//this->mEnemyData->PlayerShot = new PlayerShot(this);
	

}
Boss1::~Boss1()
{
}
void Boss1::Update(float dt)
{

	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	if (isDestroyed && mCurrentState != 4) this->SetState(new Boss1DieState(this->mBoss1Data));
	if (this->mBoss1Data->Boss1State)
	{
		this->mBoss1Data->Boss1State->Update(dt);
	}
	
	
	
	



}


void Boss1::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Boss1::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Boss1::changeAnimation(Boss1State::StateName state)
{
	switch (state)
	{
	case Boss1State::Standing:
		CurrentAnimation = Boss1Standing;
		break;
	case Boss1State::Moving:
		CurrentAnimation = Boss1Moving;
		break;
	case Boss1State::Born:
		CurrentAnimation = Boss1Born;
		break;
	
	case Boss1State::Horizontal:
		CurrentAnimation = Boss1Horizontal;
		break;
	case Boss1State::MovingZiczac:
		CurrentAnimation = Boss1Born;
		break;
	case Boss1State::Die:
		CurrentAnimation = Boss1Die;
		break;
}


	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Boss1::SetState(Boss1State *newState)
{
	delete this->mBoss1Data->Boss1State;

	this->mBoss1Data->Boss1State = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
Boss1State::StateName Boss1::getState()
{
	return mCurrentState;
}
void Boss1::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mBoss1Data->Boss1State->OnCollision(impactor, side, data);
}
void Boss1::OnCollissionWithBullet(int damage)
{
	HP = HP - damage;
	if (HP < 0) isDestroyed = true;

}