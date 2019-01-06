#include "Brick2.h"
#include "../../GameObjects/Player/Player.h"


Brick2::Brick2() {

	Brick2Standing = new Animation("Resources/Brick2.png", 1, 1, 1, 0.0f);
	Brick2Die = new Animation("Resources/Effect/BigExplosion.png", 8, 1, 8, 0.05f);
	this->mBrick2Data = new Brick2Data();
	this->mBrick2Data->Brick2 = this;
	this->SetState(new Brick2StandingState(this->mBrick2Data));
	this->HP = 3;
	entity = new Entity();
    entity->SetPosition(this->GetPosition());
	entity->SetWidth(this->GetWidth());
	entity->SetHeight(this->GetHeight());
	
}
Brick2::~Brick2()
{
}
void Brick2::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	if (this->mBrick2Data->Brick2State)
	{
		this->mBrick2Data->Brick2State->Update(dt);
	}
	


}


void Brick2::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Brick2::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Brick2::changeAnimation(Brick2State::StateName state)
{
	switch (state)
	{
	case Brick2State::Standing:
		CurrentAnimation = Brick2Standing;
		break;
	case Brick2State::Die:
		CurrentAnimation = Brick2Die;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Brick2::SetState(Brick2State *newState)
{
	delete this->mBrick2Data->Brick2State;

	this->mBrick2Data->Brick2State = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
Brick2State::StateName Brick2::getState()
{
	return mCurrentState;
}
