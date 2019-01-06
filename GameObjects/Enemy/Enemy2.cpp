#include "Enemy2.h"
Enemy2::Enemy2() {

	enemy2 = new Animation("Resources/Enemy2.png", 4, 1, 4, 0.2f);
	CurrentAnimation = enemy2;
	enemy2->SetScale(D3DXVECTOR2(2, 2));
	this->mEnemyData = new EnemyData();
	this->mEnemyData->enemy2 = this;
	this->SetReverse(true);
}
void Enemy2::Update(float dt)
{
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
}

void Enemy2::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}

void Enemy2::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(D3DXVECTOR3(GameGlobal::GetWidth() / 1.5, GameGlobal::GetHeight() / 1.5, 0));

	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(D3DXVECTOR3(GameGlobal::GetWidth() / 1.5, GameGlobal::GetHeight() / 1.5, 0));
}
