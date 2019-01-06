#include "Bullet.h"
#include "../../GameObjects/Player/Player.h"


Bullet::Bullet() {
	
	
	
}
Bullet::~Bullet()
{	
}
void Bullet::Update(float dt)
{
	
	
	
	
	
}


void Bullet::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Bullet::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(position);
	
	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
	
	
}

void Bullet::changeAnimation(BulletState::StateName state)
{
	switch (state)
	{
	case BulletState::Moving:
		CurrentAnimation = BulletMoving;
		break;
	case BulletState::Die:
		CurrentAnimation = BulletDie;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Bullet::SetState(BulletState *newState)
{
	
}
BulletState::StateName Bullet::getState()
{
	return mCurrentState;
}
void Bullet::OnCollision()
{
	isDestroyed = true;
}