#include "SpecialBullet.h"





SpecialBullet::SpecialBullet() {

	SpecialBulletFlying = new Animation("Resources/Boss3/SpecialBullet.png", 1, 1, 1, 0.0f);
	SpecialBulletDie= new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	
	this->mSpecialBulletData = new SpecialBulletData();
	this->mSpecialBulletData->SpecialBullet = this;

	this->SetState(new SpecialBulletFlyingState(this->mSpecialBulletData));
	HP = 1;
	count = 0;
	time = 400;
	
	


}
SpecialBullet::~SpecialBullet()
{
}
void SpecialBullet::Update(float dt)
{

	CurrentAnimation->Update(dt);

	Entity::Update(dt);

	if (this->mSpecialBulletData->SpecialBulletState)
	{
		this->mSpecialBulletData->SpecialBulletState->Update(dt);
	}
	count++;
	if ((HP<=0 || count == time) && this->mCurrentState!=1) this->SetState(new SpecialBulletDieState(this->mSpecialBulletData));
	
	




}


void SpecialBullet::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void SpecialBullet::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	
	CurrentAnimation->SetPosition(position);
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
	

}

void SpecialBullet::changeAnimation(SpecialBulletState::StateName state)
{
	switch (state)
	{
	case SpecialBulletState::Flying:
	{
		CurrentAnimation = SpecialBulletFlying;
		break;
	}
	case SpecialBulletState::Die:
	{
		CurrentAnimation = SpecialBulletDie;
		break;
	}
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void SpecialBullet::SetState(SpecialBulletState *newState)
{
	delete this->mSpecialBulletData->SpecialBulletState;

	this->mSpecialBulletData->SpecialBulletState = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
SpecialBulletState::StateName SpecialBullet::getState()
{
	return mCurrentState;
}
void SpecialBullet::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mSpecialBulletData->SpecialBulletState->OnCollision(impactor, side, data);
}

void SpecialBullet::GetPlayerPosition()
{

}




