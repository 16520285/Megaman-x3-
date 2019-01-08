#include "Boss3.h"





Boss3::Boss3(Player *Player) {
	Boss3Standing = new Animation("Resources/Boss3/Boss3Flying.png", 1, 1, 1, 0.0f);
	Boss3Flying = new Animation("Resources/Boss3/Boss3Flying.png", 1, 1, 1, 0.0f);
	//Boss3GenerateBee = new Animation("Resources/Boss3/Boss3GenerateBee.png", 5, 1, 5, 0.5f);
	Boss3Attack = new Animation("Resources/Boss3/Boss3Attack.png", 5, 1, 5, 0.5f);
	Boss3Preparing = new Animation("Resources/Boss3/Boss3Preparing.png", 5, 1, 5, 0.8f);
	Boss3GenerateBee = new Animation("Resources/Boss3/Boss3GenerateBee.png", 5, 1, 5, 0.5f);
	Boss3Die = new Animation("Resources/Boss3/Boss3Die.png", 1, 1, 1, 0.0f);
	
	Boss3Preparing->SetScale(D3DXVECTOR2(2, 2));
	
	Boss3GenerateBee->SetScale(D3DXVECTOR2(2, 2));
	Boss3Attack->SetScale(D3DXVECTOR2(2, 2));
	Boss3ZiczacBee = new Animation("Resources/Boss3/Boss3Flying.png", 1, 1, 1, 0.0f);
	
	Wings = new Animation("Resources/Boss3/Wings.png", 3,1,3, 0.00011f);
	Wings->SetScale(D3DXVECTOR2(2, 2));
	this->mBoss3Data = new Boss3Data();
	this->mBoss3Data->Boss3 = this;
	
	//bee = new Bee();
	//bee->SetPosition(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y);
	this->SetVx(0);
	this->SetVy(0);
	
	this->SetState(new Boss3StandingState(this->mBoss3Data));
	Wings->SetPosition(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y - wingsDistance);
	
	this->mBoss3Data->Player = Player;

	this->HP = 32;
	//this->SetState(new Boss3StandingState(this->mBoss3Data));
	//this->mEnemyData->PlayerShot = new PlayerShot(this);
	

}
Boss3::~Boss3()
{
}
void Boss3::Update(float dt)
{
	
	Wings->Update(dt);
	Wings->SetPosition(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y - wingsDistance);
	CurrentAnimation->Update(dt);
	
	Entity::Update(dt);
	//if (isDestroyed && mCurrentState!=5)
		//this->SetState(new Boss3DieState(this->mBoss3Data));
	if (this->mBoss3Data->Boss3State)
	{
		this->mBoss3Data->Boss3State->Update(dt);
	}
	
	//this->mBoss3Data->mCurrentReverse = this->mCurrentReverse;
	//if (this->mBoss3Data->Boss3->getState() == Boss3State::GenerateBee)
	if (this->mBoss3Data->Boss3->getState()== Boss3State::GenerateBee)
	{
		//bee->Update(dt);
	}
	if (this->mBoss3Data->Boss3->GetPosition().x <= (19509.3 - 125))
	{
		this->onRight = false;
	}
	else this->onRight = true;


	if (HP < 0 && mCurrentState!=5) this->SetState(new Boss3DieState(this->mBoss3Data));


}


void Boss3::SetReverse(bool flag)
{
	mCurrentReverse = flag;
}



void Boss3::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	CurrentAnimation->FlipVertical(mCurrentReverse);
	//CurrentAnimation->SetPosition(this->GetPosition());
	Wings->SetPosition(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y - wingsDistance);
	
	
	Wings->Draw(D3DXVECTOR3(CurrentAnimation->GetPosition().x, (CurrentAnimation->GetPosition().y - wingsDistance), 0), sourceRect, scale, transform, angle, rotationCenter, colorKey);
	//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	//bee->SetPosition(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y);
	//bee->Draw(D3DXVECTOR3(CurrentAnimation->GetPosition().x, CurrentAnimation->GetPosition().y, 0), sourceRect, scale, transform, angle, rotationCenter, colorKey);
	CurrentAnimation->SetPosition(position);
	CurrentAnimation->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
	
	
}

void Boss3::changeAnimation(Boss3State::StateName state)
{
	switch (state)
	{
	case Boss3State::Flying:
	{
		CurrentAnimation = Boss3Flying;
		break;
	}
	case Boss3State::Attack:
		CurrentAnimation = Boss3Attack;
		break;
	case Boss3State::GenerateBee:
		CurrentAnimation = Boss3GenerateBee;
		break;
	case Boss3State::Preparing:
		CurrentAnimation = Boss3Preparing;
		break;
	case Boss3State::Born:
		CurrentAnimation = Boss3Flying;
		break;
	case Boss3State::ZiczacBee:
			CurrentAnimation = Boss3ZiczacBee;
			break;
	case Boss3State::Die:
		CurrentAnimation = Boss3Die;
		break;
	case Boss3State::Standing:
		CurrentAnimation = Boss3Standing;
		break;
	}

	this->width = CurrentAnimation->GetWidth();
	this->height = CurrentAnimation->GetHeight();
}

void Boss3::SetState(Boss3State *newState)
{
	delete this->mBoss3Data->Boss3State;

	this->mBoss3Data->Boss3State = newState;

	this->changeAnimation(newState->GetState());

	mCurrentState = newState->GetState();
}
Boss3State::StateName Boss3::getState()
{
	return mCurrentState;
}
void Boss3::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mBoss3Data->Boss3State->OnCollision(impactor, side, data);
}

void Boss3::GetPlayerPosition()
{
	
}

bool Boss3::OnRight()
{
	return this->onRight;
}

void Boss3::OnCollissionWithBullet(int damage)
{
	HP = HP - damage;
	if (HP < 0) isDestroyed = true;

}
void Boss3::onFired()
{
	for (size_t i = 0; i < 4; i++)
	{
			Bee *temp1 = new Bee();
			if (this->mCurrentReverse) temp1->SetReverse(true);
			else temp1->SetReverse(false);
			temp1->SetPosition(this->GetPosition());
			mListBee.push_back(temp1);
	}
	
}