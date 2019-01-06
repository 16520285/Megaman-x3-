#include "Brick.h"
#include "../../GameObjects/Player/Player.h"


Brick::Brick() {

	BrickStanding = new Animation("Resources/Brick.png", 1, 1, 1, 0.0f);
	BrickDie = new Animation("Resources/Effect/BigExplosion.png", 8, 1, 8, 0.05f);
	this->mBrickData = new BrickData();
	this->mBrickData->Brick = this;
	this->SetState(new BrickStandingState(this->mBrickData));
	this->HP = 3;
}
Brick::~Brick()
{
}
void Brick::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	if (this->mBrickData->BrickState)
	{
		this->mBrickData->BrickState->Update(dt);
	}
	


}


void Brick::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Brick::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Brick::changeAnimation(BrickState::StateName state)
{
	switch (state)
	{
	case BrickState::Standing:
		CurrentAnimation = BrickStanding;
		break;
	case BrickState::Die:
		CurrentAnimation = BrickDie;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Brick::SetState(BrickState *newState)
{
	delete this->mBrickData->BrickState;

	this->mBrickData->BrickState = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
BrickState::StateName Brick::getState()
{
	return mCurrentState;
}
Entity* Brick::getEntity()
{
	Entity *temp = new Entity();
	temp->SetPosition(this->GetPosition());
	temp->SetWidth(this->GetWidth());
	temp->SetHeight(this->GetHeight());
	return temp;
}
