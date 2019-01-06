#include "Shuriken.h"





Shuriken::Shuriken() {

	
	ShurikenMoving = new Animation("Resources/Boss2/ShurikenMoving.png", 7, 1, 7, 0.0001f);
	ShurikenStick = new Animation("Resources/Boss2/ShurikenStick.png", 1, 1, 1, 0.0f);
	ShurikenDie = new Animation("Resources/Enemy1/DieState.png", 7, 1, 7, 0.0f);
	ShurikenMoving->SetScale(D3DXVECTOR2(2, 2));
	ShurikenStick->SetScale(D3DXVECTOR2(2, 2));


	this->mShurikenData = new ShurikenData();
	this->mShurikenData->Shuriken = this;

	this->SetState(new ShurikenMovingState(this->mShurikenData));






}
Shuriken::~Shuriken()
{
}
void Shuriken::Update(float dt)
{
		
	

	

	CurrentAnimation->Update(dt);

	Entity::Update(dt);

	if (this->mShurikenData->ShurikenState)
	{
		this->mShurikenData->ShurikenState->Update(dt);
	}






}


void Shuriken::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Shuriken::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());

	CurrentAnimation->SetPosition(position);
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Shuriken::changeAnimation(ShurikenState::StateName state)
{
	switch (state)
	{
	case ShurikenState::Moving:
	
		CurrentAnimation = ShurikenMoving;
		break;
	case ShurikenState::Stick:

		CurrentAnimation = ShurikenStick;
		break;
	case ShurikenState::Die:

		CurrentAnimation = ShurikenDie;
		break;
	
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Shuriken::SetState(ShurikenState *newState)
{
	delete this->mShurikenData->ShurikenState;

	this->mShurikenData->ShurikenState = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
ShurikenState::StateName Shuriken::getState()
{
	return mCurrentState;
}
void Shuriken::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mShurikenData->ShurikenState->OnCollision(impactor, side, data);
}

void Shuriken::GetPlayerPosition()
{

}




