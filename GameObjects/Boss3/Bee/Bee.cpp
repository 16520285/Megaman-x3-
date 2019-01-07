#include "Bee.h"





Bee::Bee() {

	BeeFlying = new Animation("Resources/Boss3/Bee.png", 6, 1, 6, 0.0001f);
	BeeDie= new Animation("Resources/enemy1/DieState.png", 8, 1, 8, 0.05f);
	BeeFlying->SetScale(D3DXVECTOR2(2, 2));
	
	
	
	this->mBeeData = new BeeData();
	this->mBeeData->Bee = this;

	this->SetState(new BeeFlyingState(this->mBeeData));
	HP = 1;
	count = 0;
	time = 400;
	
	


}
Bee::~Bee()
{
}
void Bee::Update(float dt)
{
/*
	if (this->mBeeData->Bee->GetPosition().x <= (19509.3 - 425) || this->mBeeData->Bee->GetPosition().x >= (19509.3 + 100))
	{
		this->mBeeData->Bee->SetVx(0);
		this->mBeeData->Bee->SetVy(0);
	}
	*/
	
	CurrentAnimation->Update(dt);

	Entity::Update(dt);

	if (this->mBeeData->BeeState)
	{
		this->mBeeData->BeeState->Update(dt);
	}
	count++;
	if ((HP<=0 || count == time) && this->mCurrentState!=1) this->SetState(new BeeDieState(this->mBeeData));
	
	




}


void Bee::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Bee::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	
	CurrentAnimation->SetPosition(position);
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
	

}

void Bee::changeAnimation(BeeState::StateName state)
{
	switch (state)
	{
	case BeeState::Flying:
	{
		CurrentAnimation = BeeFlying;
		break;
	}
	case BeeState::Die:
	{
		CurrentAnimation = BeeDie;
		break;
	}
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Bee::SetState(BeeState *newState)
{
	delete this->mBeeData->BeeState;

	this->mBeeData->BeeState = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
BeeState::StateName Bee::getState()
{
	return mCurrentState;
}
void Bee::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mBeeData->BeeState->OnCollision(impactor, side, data);
}

void Bee::GetPlayerPosition()
{

}




