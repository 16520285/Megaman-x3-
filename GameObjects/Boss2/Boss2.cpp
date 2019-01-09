#include "Boss2.h"





Boss2::Boss2() {

	
	Boss2Standing = new Animation("Resources/Boss2/Boss2Standing.png", 1, 1, 1, 0.0f);
	//Boss2Standing->SetScale(D3DXVECTOR2(2, 2));
	
	Boss2Shooting = new Animation("Resources/Boss2/Boss2Shooting.png", 3, 1, 3, 0.2f);
	//Boss2Shooting->SetScale(D3DXVECTOR2(2, 2));
	Boss2Die =new Animation("Resources/Effect/BigExplosion.png", 8, 1, 8, 0.05f);
	Boss2Attack = new Animation("Resources/Boss2/Boss2Attack.png", 1, 1, 1, 0.0f);
	//Boss2Attack->SetScale(D3DXVECTOR2(2, 2));
	this->mBoss2Data = new Boss2Data();
	this->mBoss2Data->Boss2 = this;
	this->HP = 32;
	
	

	this->SetState(new Boss2StandingState(this->mBoss2Data));
	


	

}
Boss2::~Boss2()
{
}
void Boss2::Update(float dt)
{

	
	CurrentAnimation->Update(dt);

	Entity::Update(dt);
	if (isDestroyed && mCurrentState != 3) this->SetState(new Boss2DieState(this->mBoss2Data));
	if (this->mBoss2Data->Boss2State)
	{
		this->mBoss2Data->Boss2State->Update(dt);
	}
	this->isRight();


}


void Boss2::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Boss2::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	


	
	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	//bee->SetPosition(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y);
	//bee->Draw(D3DXVECTOR3(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y, 0), sourceRect, scale, transform, angle, rotationCenter, colorKey);
	CurrentAnimation->SetPosition(position);
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);


}

void Boss2::changeAnimation(Boss2State::StateName state)
{
	switch (state)
	{
	
	case Boss2State::Attack:
		CurrentAnimation = Boss2Attack;
		break;
	case Boss2State::Shooting:
		CurrentAnimation = Boss2Shooting;
		break;
	case Boss2State::Standing:
		CurrentAnimation = Boss2Standing;
		break;
	case Boss2State::Die:
		CurrentAnimation = Boss2Die;
		break;



	

	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Boss2::SetState(Boss2State *newState)
{
	delete this->mBoss2Data->Boss2State;

	this->mBoss2Data->Boss2State = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
Boss2State::StateName Boss2::getState()
{
	return mCurrentState;
}
void Boss2::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mBoss2Data->Boss2State->OnCollision(impactor, side, data);
}

bool Boss2::isRight()
{
	if (this->mBoss2Data->Boss2->GetPosition().x <= 14417.3 - 200)
		return false;
	return true;
}
void Boss2::onFired()
{
	Shuriken *tempbullet = new Shuriken();
	if (this->mCurrentReverse) tempbullet->SetReverse(true);
	else tempbullet->SetReverse(false);
	tempbullet->SetPosition(this->GetPosition());
	mListBoss2Bullet.push_back(tempbullet);

}
void Boss2::OnCollissionWithBullet(int damage)
{
	HP = HP - damage;
	if (HP < 0)
		isDestroyed = true;

}





