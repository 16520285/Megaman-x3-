#include "Door.h"
#include "../../GameObjects/Player/Player.h"


Door::Door() {

	DoorOpen = new Animation("Resources/Door/door1.png", 9, 1, 9, 0.3f);
	DoorOpened = new Animation("Resources/Door/DoorOpened.png", 1, 1, 1, 0.0f);
	DoorClose = new Animation("Resources/Door/door2.png", 17, 1, 17, 0.3f);
	DoorClosed= new Animation("Resources/Door/DoorClosed.png", 1, 1, 1, 0.0f);
	DoorStanding = new Animation("Resources/Door/DoorStanding.png", 1, 1, 1, 0.0f);
	
	this->mDoorData = new DoorData();
	this->mDoorData->Door = this;
	this->SetState(new DoorStandingState(this->mDoorData));
	key = true;
	entity = new Entity();
	entity->SetPosition(this->GetPosition());
	entity->SetWidth(this->GetWidth());
	entity->SetHeight(this->GetHeight());
}
Door::~Door()
{
}
void Door::Update(float dt)
{
	
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	if (this->mDoorData->DoorState)
	{
		this->mDoorData->DoorState->Update(dt);
	}
	
	
	
	


}


void Door::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Door::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Door::changeAnimation(DoorState::StateName state)
{
	switch (state)
	{
	case DoorState::Standing:
		CurrentAnimation = DoorStanding;
		break;
	case DoorState::Open:
		CurrentAnimation = DoorOpen;
		break;
	case DoorState::Opened:
		CurrentAnimation = DoorOpened;
		break;
	case DoorState::Close:
		CurrentAnimation = DoorClose;
		break;
	case DoorState::Closed:
		CurrentAnimation = DoorClosed;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Door::SetState(DoorState *newState)
{
	delete this->mDoorData->DoorState;

	this->mDoorData->DoorState = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
DoorState::StateName Door::getState()
{
	return mCurrentState;
}
