#include "Elevator.h"
Elevator::Elevator() {

	//Elevator = new Animation("Resources/Enemy/Elevator.png", 5, 1, 5, 0.035f);
	CurrentAnimation = new Animation("Resources/elevator.png", 3, 3, 1, 0.035f);
	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight()/2;
	

}
void Elevator::Update(float dt)
{
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	
}

void Elevator::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}

void Elevator::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
}
