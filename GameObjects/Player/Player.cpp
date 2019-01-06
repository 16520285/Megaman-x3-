#include "Player.h"
#include "PlayerStandingState.h"
#include "PlayerJumpingState.h"
#include "PlayerJumpingShotState.h"
#include "PlayerRunningShot.h"
#include "../../GameComponents/GameLog.h"
#include "../../GameComponents/Sound.h"

Player::Player()
{
	playerStanding = new Animation("Resources/playerStanding.png", 4, 1, 4, 0.1f);
	playerJumping = new Animation("Resources/playerJumping.png", 3, 1, 3, 0.2f);
	playerFalling = new Animation("Resources/playerFalling.png", 1, 1, 1, 0.2f);
	playerRunning = new Animation("Resources/playerRunning.png", 11, 1, 11, 0.05f);
	playerSurfing = new Animation("Resources/playerSurfing.png", 1, 1, 1, 0.1f);
	playerSurfingShot = new Animation("Resources/playerSurfingShot.png", 1, 1, 1, 0.1f);
	
	playerRunningShot = new Animation("Resources/playerRunningShot.png", 11, 1, 11, 0.05f);
	playerJumpingShot = new Animation("Resources/playerJumpingShot.png", 3, 1, 3, 0.2f);
	playerStandingShot = new Animation("Resources/playerStandingShot.png", 1, 1, 1, 0.1f);
	playerClimbingShot = new Animation("Resources/playerClimbingShot.png", 1, 1, 1, 0.1f);
	playerWalling = new Animation("Resources/playerWall.png", 1, 1, 1, 0.1f);
	playerWallingShot = new Animation("Resources/playerWallShot.png", 1, 1, 1, 0.1f);
	playerHurting = new Animation("Resources/playerAttacked.png", 2, 1, 2, 0.1f);
	playerDie = new Animation("Resources/playerDieState.png", 1, 1, 1, 0.0f);
	

    this->mPlayerData = new PlayerData();
    this->mPlayerData->player = this;
    this->vx = 0;
    this->vy = 0;
	this->HP = 16;
	this->SetState(new PlayerFallingState(this->mPlayerData));
    //this->SetState(new PlayerStandingState(this->mPlayerData));

	allowJump = true;
	allowShot = true;
	allowJumpingShot = true;
}

Player::~Player()
{
}

void Player::Update(float dt)
{   
	FindFollowAnimation();
	
    CurrentAnimation->Update(dt);
	if (FollowAnimation)  FollowAnimation->Update(dt);
    if (this->mPlayerData->state)
    {
        this->mPlayerData->state->Update(dt);
    }

    Entity::Update(dt);

	if (charging)
	{
		count++;
		if (count > 16) level = 2;
		if (count > 85) level = 3;
		if (charged1==NULL && level==2) charged1 = new Animation("Resources/Effect/Charged1.png", 11, 1, 11, 0.02f);
		if (charged2 == NULL && level == 3) {
			charged2 = new Animation("Resources/Effect/Charged2.png", 11, 1, 11, 0.02f);
			charged1 = NULL;
		}
	//	charged1->SetPosition(this->GetPosition());
	}
	else {
		this->charged1=NULL;
		this->charged2 = NULL;
		count = 0;
	}
	if (charged1 != NULL) 	charged1->Update(dt);
	if (charged2 != NULL) charged2->Update(dt);
		
	
	for (int i = 0; i < mListPlayerBullet.size(); i++)
	{
		
		if (mListPlayerBullet.at(i)->isDeleted) {
			delete mListPlayerBullet.at(i);
			mListPlayerBullet.erase(mListPlayerBullet.begin() + i);
			
		}
	}
	
	if (nobody)
	{
		clock++;
		if (clock == 70) {
			nobody = false;
			clock = 0;
		}
	}

	if (HP ==0) this->SetState(new PlayerDieState(this->mPlayerData));
	
}

void Player::HandleKeyboard(std::map<int, bool> keys)
{
    if (this->mPlayerData->state)
    {
        this->mPlayerData->state->HandleKeyboard(keys);
    }
}

void Player::OnKeyPressed(int key)
{
	if (key == 0x58)
	{
		level = 1;
		if (count > 16) level = 2;
		if (count > 85) level = 3;
		charging = true;
		
		//GAMELOG("count: %d",charging);
	}
    if (key == VK_SPACE)
    {
        if (allowJump)
        {
            if (mCurrentState == PlayerState::Running || mCurrentState == PlayerState::Standing || mCurrentState == PlayerState::RunningShot || mCurrentState == PlayerState::StandingShot)
            {
                this->SetState(new PlayerJumpingState(this->mPlayerData));
            }

            allowJump = false;
        }
		Sound::getInstance()->play("PlayerJumping", false, 1);
    }
	if (key == 0x58 && mCurrentState == PlayerState::Running)
	{
		charging = true;
		if (allowShot)
		{
			this->SetState(new PlayerRunningShotState(this->mPlayerData));
			//return;
			allowShot = false;





		}
	}
	if (key == 0x58 && mCurrentState == PlayerState::Jumping)
	{
		charging = true;
		if (allowShot)
		{
			this->SetState(new PlayerJumpingShotState(this->mPlayerData));
			//return;
			allowShot = false;

		}

	}
	
}

void Player::OnKeyUp(int key)
{
    if (key == VK_SPACE)
        allowJump = true;
	if (key == 0x58)
	{
		Sound::getInstance()->play("PlayerShooting", false, 1);
		allowShot = true;
		
		charging = false;
	
		//GAMELOG("level: %d", level);
		OnFired(level);
		//if (key == 0x58) GAMELOG("2222");

	}
	/*if (key == 0x59)
		allowJumpingShot = true;*/

	
	
}

void Player::SetReverse(bool flag)
{
    mCurrentReverse = flag;
}

void Player::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
    CurrentAnimation->FlipVertical(mCurrentReverse);
    //CurrentAnimation->SetPosition(this->GetPosition());
	CurrentAnimation->SetPosition(D3DXVECTOR3(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2, 0));

//    CurrentAnimation->Draw(D3DXVECTOR3(posX, posY, 0));
	CurrentAnimation->Draw(D3DXVECTOR3(GameGlobal::GetWidth()/ 2, GameGlobal::GetHeight()/ 2, 0));
	if (charged1) {
		charged1->Draw(D3DXVECTOR3(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2, 0));
	}
	if (charged2) {
		charged2->Draw(D3DXVECTOR3(GameGlobal::GetWidth() / 2, GameGlobal::GetHeight() / 2, 0));
	}
}

void Player::SetState(PlayerState *newState)
{
    delete this->mPlayerData->state;

    this->mPlayerData->state = newState;

    this->changeAnimation(newState->GetState());

    mCurrentState = newState->GetState();
}

RECT Player::GetBound()
{
    RECT rect;
	
    rect.left = this->posX - CurrentAnimation->GetWidth() / 2;
    rect.right = rect.left + CurrentAnimation->GetWidth();
    rect.top = this->posY - CurrentAnimation->GetHeight() / 2;
    rect.bottom = rect.top + CurrentAnimation->GetHeight();
	/*
	rect.left = this->posX - this->GetWidth()/2;
	rect.right = rect.left + this->GetWidth();
	rect.top = this->posY - this->GetHeight()/2;
	rect.bottom = rect.top + this->GetHeight();*/
    return rect;
}

void Player::changeAnimation(PlayerState::StateName state)
{
    switch (state)
    {
        case PlayerState::Running:
            CurrentAnimation = playerRunning;
            break;

        case PlayerState::Standing:
            CurrentAnimation = playerStanding;
            break;

        case PlayerState::Falling:
            CurrentAnimation = playerFalling;
            break;

        case PlayerState::Jumping:
            CurrentAnimation = playerJumping;
            break;
		case PlayerState::Surfing:
			CurrentAnimation = playerSurfing;
			break;
		case PlayerState::SurfingShot:
			CurrentAnimation = playerSurfingShot;
			break;
		case PlayerState::RunningShot:
			CurrentAnimation = playerRunningShot;
			break;
		case PlayerState::JumpingShot:
			CurrentAnimation = playerJumpingShot;
			break;
		case PlayerState::StandingShot:
			CurrentAnimation = playerStandingShot;
			break;
		case PlayerState::ClimbingShot:
			CurrentAnimation = playerClimbingShot;
			break;
		case PlayerState::Walling:
			CurrentAnimation = playerWalling;
			break;
		case PlayerState::WallingShot:
			CurrentAnimation = playerWallingShot;
			break;
		case PlayerState::Hurting:
			CurrentAnimation = playerHurting;
			break;
		case PlayerState::Die:
			CurrentAnimation = playerDie;
			break;
    }

    this->width = CurrentAnimation->GetWidth();
    this->height = CurrentAnimation->GetHeight();
}

Player::MoveDirection Player::getMoveDirection()
{
    if (this->vx > 0)
    {
        return MoveDirection::MoveToRight;
    }
    else if (this->vx < 0)
    {
        return MoveDirection::MoveToLeft;
    }

    return MoveDirection::None;
}

PlayerState::StateName Player::getState()
{
    return mCurrentState;
}
void Player::OnNoCollisionWithBottom()
{
	if (mCurrentState != PlayerState::Jumping && mCurrentState != PlayerState::Falling)
	{
		this->SetState(new PlayerFallingState(this->mPlayerData));
	}
}
void Player::OnCollision(Entity *impactor, Entity::CollisionReturn data, Entity::SideCollisions side)
{
	this->mPlayerData->state->OnCollision(impactor, side, data);
}
void Player::FindFollowAnimation()
{
	if (CurrentAnimation == playerRunning) FollowAnimation = playerRunningShot;
	if (CurrentAnimation == playerRunningShot) FollowAnimation = playerRunning;
	if (CurrentAnimation == playerJumping) FollowAnimation = playerJumpingShot;
	if (CurrentAnimation == playerJumpingShot) FollowAnimation = playerJumping;
}
void Player::OnCollisionWithEnemy()
{
	  this->SetState(new PlayerHurtingState(this->mPlayerData));
}

void Player::OnFired(int _level)
{
	
		PlayerBullet *tempbullet = new PlayerBullet(_level);
		if (this->mCurrentReverse) tempbullet->SetReverse(true);
		else tempbullet->SetReverse(false);
		if (this->getState() == 12) tempbullet->SetReverse(!tempbullet->mCurrentReverse);
		tempbullet->SetPosition(this->GetPosition());
		mListPlayerBullet.push_back(tempbullet);
	

	
}