#include "Enemy1Shot.h"
#include "../../GameObjects/Player/Player.h"


Enemy1Shot::Enemy1Shot(Enemy1 *enemy1) {

	bullet = new Animation("Resources/Enemy/bullet.png", 1, 1, 1, 0.0f);
	
	CurrentAnimation = bullet;
	bullet->SetScale(D3DXVECTOR2(3, 3));
	enemy1Position = enemy1->GetPosition();
	this->shotData = new EnemyData1();
	//this->shotData->enemyShot = this;

}
Enemy1Shot::~Enemy1Shot()
{
}
void Enemy1Shot::Update(float dt)
{
	CurrentAnimation->Update(dt);
	Entity::Update(dt);
	//this->shotData->enemy1Shot->AddVx(-0.5f);
	
	//this->mEnemyData1->Enemy1Shot->AddVx(-0.5);
	/*if (this->mEnemyData->Enemy1Shot->GetPosition().x <=
		this->mEnemyData->Enemy1Shot->AddVx(0.5);*/
		//  bullet->Update(dt);


}

void Enemy1Shot::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



D3DXVECTOR3 Enemy1Shot::GetEnemy1Position()
{
	return enemy1Position;

}

void Enemy1Shot::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(GetEnemy1Position());
	
	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(GetEnemy1Position(), sourceRect, scale, transform, angle, rotationCenter, colorKey);
	

}
