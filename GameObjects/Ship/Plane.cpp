#include "Plane.h"
#include "../../GameComponents/GameLog.h"
Plane::Plane() {

	//Plane = new Animation("Resources/Enemy/Plane.png", 5, 1, 5, 0.035f);
	CurrentAnimation = new Animation("Resources/plane.png", 4, 1, 4, 0.1f);
	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
	count = 0;
	time = 400;
	isDown = true;
}
void Plane::Update(float dt)
{
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	count++;
	if (count == time)
	{
		isDown = !isDown;
		count = 0;
	}
	if (this->isDown) this->SetVy(100);
	else this->SetVy(-100);
}

void Plane::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}

void Plane::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
}
